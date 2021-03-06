/*
 * interrutps.cpp
 *
 *  Created on: 17.12.2014
 *      Author: Michael
 */

#include <stmlib/nvic.hpp>
#include <stmlib/core.hpp>
#include <stmlib/trace.h>

extern "C" {

	void unused_interrupt() {
		for(;;);
	}

	void NMIVector() {
		for(;;);
	}

	void HardFaultVector() {
		for(;;);
	}


	void MemManageVector() {
		for(;;);
	}
/*
	enum { r0, r1, r2, r3, r12, lr, pc, psr};

	void BusFaultHandler(uint32 stack[])
	{
		trace_printf(0, "r0 :   %u\n", stack[r0]);
		trace_printf(0, "r1 :   %u\n", stack[r1]);
		trace_printf(0, "r2 :   %u\n", stack[r2]);
		trace_printf(0, "r3 :   %u\n", stack[r3]);
		trace_printf(0, "r12:   %u\n", stack[r12]);
		trace_printf(0, "lr:  0x%x\n", stack[lr]);
		trace_printf(0, "pc:  0x%x\n", stack[pc]);
		trace_printf(0, "psr: 0x%x\n", stack[psr]);

		for(;;);
	}
*/
	void BusFaultVector() {
/*
		__asm("TST lr, #4");
		__asm("ITE EQ");
		__asm("MRSEQ r0, MSP");
		__asm("MRSNE r0, PSP");
		__asm("B BusFaultHandler");
*/
/*
		uint32 bfar = core::device.bfar.get();
		uint32 cfsr = core::device.cfsr.get();
		uint8  mmfsr = cfsr & 0xFF;
		uint8  bfsr  = (cfsr >>  8) & 0xFF;
		uint16 ufsr  = (cfsr >> 16) & 0xFFFF;
*/
		for(;;);
	}

	void UsageFaultVector() {
		for(;;);
	}

	void unimplemented_handler() {
		for(;;);
	}

}


namespace nvic {

	using isr_type = void (*)();

}

extern "C" {

	extern uint32 __main_stack_end__;
	extern void ResetHandler(void);
	extern void NMIVector(void);
//	extern void HardFaultVector(void);
//	extern void MemManageVector(void);
//	extern void BusFaultVector(void);
//	extern void UsageFaultVector(void);
	extern void SVCallVector(void);
	extern void DebugMonitorVector(void);
	extern void PendSVVector(void);
	extern void SysTickVector(void);

}

namespace nvic {

	template<> void isr<IRQ::WWDG>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::PVD>()             __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TAMPER>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::RTC_WKUP>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::FLASH>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::RCC>()             __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI0>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI1>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI2>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI3>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI4>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream0>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream1>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream2>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream3>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream4>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream5>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream6>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::ADC>()             __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN1_TX>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN1_RX0>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN1_RX1>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN1_SCE>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI9_5>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM1_BRK>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM1_UP>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM1_TRG_COM>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM1_CC>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM2>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM3>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM4>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C1_EV>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C1_ER>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C2_EV>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C2_ER>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::SPI1>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::SPI2>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::USART1>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::USART2>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::USART3>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::EXTI15_10>()       __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::RTC_ALARM>()       __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTG_FS_WKUP>()     __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM8_BRK>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM8_UP>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM8_TRG_COM>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM8_CC>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA1_Stream7>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::FSMC>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::SDIO>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM5>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::SPI3>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::UART4>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::UART5>()           __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM6>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::TIM7>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream0>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream1>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream2>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream3>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream4>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::ETH>()             __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::ETH_WKUP>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN2_TX>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN2_RX0>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN2_RX1>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CAN2_SCE>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTG_FS>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream5>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream6>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DMA2_Stream7>()    __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::USART6>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C3_EV>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::I2C3_ER>()         __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTG_HS_EP1_OUT>()  __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTF_HS_EP1_IN>()   __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTG_HS_WKUP>()     __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::OTG_HS>()          __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::DCMI>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::CRYP>()            __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::HASH_RNG>()        __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::FPU>()             __attribute__ ((weak, alias ("unused_interrupt")));
	template<> void isr<IRQ::Undefined>()       __attribute__ ((weak, alias ("unused_interrupt")));

	__attribute__ ((section("vectors"))) __attribute__ ((used))
	isr_type  vectors[98] {
		(isr_type)&__main_stack_end__,
		ResetHandler,
		::NMIVector,
		::HardFaultVector,
		::MemManageVector,
		::BusFaultVector,
		::UsageFaultVector,
		isr<IRQ::Undefined>,
		isr<IRQ::Undefined>,
		isr<IRQ::Undefined>,
		isr<IRQ::Undefined>,
		SVCallVector,
		/* DebugMonitorVector, */ isr<IRQ::Undefined>,
		isr<IRQ::Undefined>,
		/* PendSVVector, */ isr<IRQ::Undefined>,
		SysTickVector,

/*0*/	isr<IRQ::WWDG>,
		isr<IRQ::PVD>,
		isr<IRQ::TAMPER>,
		isr<IRQ::RTC_WKUP>,
		isr<IRQ::FLASH>,
		isr<IRQ::RCC>,
		isr<IRQ::EXTI0>,
		isr<IRQ::EXTI1>,
		isr<IRQ::EXTI2>,
		isr<IRQ::EXTI3>,
/*10*/	isr<IRQ::EXTI4>,
		isr<IRQ::DMA1_Stream0>,
		isr<IRQ::DMA1_Stream1>,
		isr<IRQ::DMA1_Stream2>,
		isr<IRQ::DMA1_Stream3>,
		isr<IRQ::DMA1_Stream4>,
		isr<IRQ::DMA1_Stream5>,
		isr<IRQ::DMA1_Stream6>,
		isr<IRQ::ADC>,
		isr<IRQ::CAN1_TX>,
/*20*/	isr<IRQ::CAN1_RX0>,
		isr<IRQ::CAN1_RX1>,
		isr<IRQ::CAN1_SCE>,
		isr<IRQ::EXTI9_5>,
		isr<IRQ::TIM1_BRK>,
		isr<IRQ::TIM1_UP>,
		isr<IRQ::TIM1_TRG_COM>,
		isr<IRQ::TIM1_CC>,
		isr<IRQ::TIM2>,
		isr<IRQ::TIM3>,
/*30*/	isr<IRQ::TIM4>,
		isr<IRQ::I2C1_EV>,
		isr<IRQ::I2C1_ER>,
		isr<IRQ::I2C2_EV>,
		isr<IRQ::I2C2_ER>,
		isr<IRQ::SPI1>,
		isr<IRQ::SPI2>,
		isr<IRQ::USART1>,
		isr<IRQ::USART2>,
		isr<IRQ::USART3>,
/*40*/	isr<IRQ::EXTI15_10>,
		isr<IRQ::RTC_ALARM>,
		isr<IRQ::OTG_FS_WKUP>,
		isr<IRQ::TIM8_BRK>,
		isr<IRQ::TIM8_UP>,
		isr<IRQ::TIM8_TRG_COM>,
		isr<IRQ::TIM8_CC>,
		isr<IRQ::DMA1_Stream7>,
		isr<IRQ::FSMC>,
		isr<IRQ::SDIO>,
/*50*/	isr<IRQ::TIM5>,
		isr<IRQ::SPI3>,
		isr<IRQ::UART4>,
		isr<IRQ::UART5>,
		isr<IRQ::TIM6>,
		isr<IRQ::TIM7>,
		isr<IRQ::DMA2_Stream0>,
		isr<IRQ::DMA2_Stream1>,
		isr<IRQ::DMA2_Stream2>,
		isr<IRQ::DMA2_Stream3>,
/*60*/	isr<IRQ::DMA2_Stream4>,
		isr<IRQ::ETH>,
		isr<IRQ::ETH_WKUP>,
		isr<IRQ::CAN2_TX>,
		isr<IRQ::CAN2_RX0>,
		isr<IRQ::CAN2_RX1>,
		isr<IRQ::CAN2_SCE>,
		isr<IRQ::OTG_FS>,
		isr<IRQ::DMA2_Stream5>,
		isr<IRQ::DMA2_Stream6>,
/*70*/	isr<IRQ::DMA2_Stream7>,
		isr<IRQ::USART6>,
		isr<IRQ::I2C3_EV>,
		isr<IRQ::I2C3_ER>,
		isr<IRQ::OTG_HS_EP1_OUT>,
		isr<IRQ::OTF_HS_EP1_IN>,
		isr<IRQ::OTG_HS_WKUP>,
		isr<IRQ::OTG_HS>,
		isr<IRQ::DCMI>,
		isr<IRQ::CRYP>,
		isr<IRQ::HASH_RNG>,
		isr<IRQ::FPU>
	};

}


