#ifndef STMLIB_ETH_LWIP_ONETHREAD_LWIP_THREAD_HPP__
#define STMLIB_ETH_LWIP_ONETHREAD_LWIP_THREAD_HPP__

#include <stmlib_config.hpp>
#ifdef STMLIB_LWIP_ONETHREAD

#include <microptp/ports/cortex_m4_onethread/port.hpp>
#include <microlib/variant.hpp>
#include <microlib/pool.hpp>
#include <microlib/static_heap.hpp>
#include <microlib/circular_buffer.hpp>
#include <thread.hpp>
#include <lwip/tcpip.h>
#include <cpp_wrappers/ch.hpp>
#include <stmlib/stmtypes.hpp>

namespace eth {

	namespace lwip {

		enum class ThreadEvents {
		};

		struct ip_addr {
			ip_addr()
			{
			}

			ip_addr(uint32 a, uint32 b, uint32 c, uint32 d)
				: addr{ (a << 0) | (b << 8) | (c << 16) | (d << 24) }
			{
			}

			ip_addr_t addr;
		};
		
		namespace detail {

			struct timeout_data {
				timeout_data() = default;
				timeout_data(const timeout_data&) = default;
				timeout_data(timeout_data&&) = default;
				timeout_data& operator=(const timeout_data&) = default;
				timeout_data(void(*fn_)(void*), void* arg_, uint32 when_)
					: fn(fn_), arg(arg_), when(when_)
				{}

				void(*fn)(void*);
				void* arg;
				uint32 when;
			};

			template< typename T, typename S = typename std::enable_if<std::is_unsigned<T>::value>::type >
			bool time_overflow_compare(T a, T b)
			{
				return T(b - a) <= (std::numeric_limits<T>::max() / 2);
			}

			struct time_overflow_compare_struct {
				bool operator()(const timeout_data& a, const timeout_data& b) {
					return time_overflow_compare(a.when, b.when);
				}
			};

		}

		// IP-Thread which runs a PTP-Clock
		class LwipThread : public util::static_thread_crtp<LwipThread, 4096>
		{
		public:
			LwipThread();
			msg_t operator()();

			// singleton anti-pattern
			static LwipThread& get()
			{
				static LwipThread thread;
				return thread;
			}

			// pre-run config
		public:
			void set_ip(ip_addr ip);
			void set_netmask(ip_addr netmask);
			void set_gateway(ip_addr gateway);
			void set_mac_address(const uint8 (&arr)[6]);

			// in-thread routines
		public:
			void add_timeout_thread   (uint32 when, void (*fn)(void*), void* arg);
			void remove_timeout_thread(void(*fn)(void*), void* arg);

			// Event Handling
		public:
			using thread_message = util::static_union< ThreadEvents >;
			using message_ptr = util::pool_ptr<thread_message>;
			message_ptr acquire_message();
			message_ptr acquire_message_i();

			void post_message  (message_ptr msg);
			void post_message_i(message_ptr msg);

			void post_event  (ThreadEvents);
			void post_event_i(ThreadEvents);

			void on_rx();
			void on_tx();

		private:
			static err_t ethernetif_init_static(struct netif* netif);
			err_t ethernetif_init(netif* netif);

			void init_lwip();
			void init_ptp();

			uint32 get_next_timer();
			void process_timers();

			void process_ptp();

			void on_event(ThreadEvents event);

		private:
			util::pool< thread_message, 8 > message_pool_;
			util::circular_buffer2<util::pool_ptr<thread_message>, 8> mailbox_;
			util::static_heap< detail::timeout_data, 8, detail::time_overflow_compare_struct > unprecise_timers_;

			//chibios_rt::MailboxBuffer<32> mailbox_;

			ip_addr ip_; //(0, 0, 0, 0);
			ip_addr netmask_; //(255, 255, 255, 0);
			ip_addr gateway_; //(0, 0, 0, 0);
			uint8 mac_addr_[6];

			netif interface_;

			uptp::Config ptp_config_;
			uptp::SystemPort ptp_clock_;

			uint8 ptp_button_debounce_;
			bool ptp_clock_enabled_;
		};
		
	}

}

#endif

#endif