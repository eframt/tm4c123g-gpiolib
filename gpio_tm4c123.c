/*
 *  gpio_tm4c123g.c
 *
 *  Created on: 01/06/2017
 *  Author: Efrain Martinez
 */
 
#include "include/tm4c123gh6pm.h"
#include "include/gpio_tm4c123.h"
#include "include/hw_types.h"
#include "include/drvlib_tm4c123g.h"
#include <stdint.h>
#include <stdbool.h>


void PortIOConfig(uint32_t baseAddr, uint8_t digPins, uint8_t pinDir, uint8_t padConf)
{
	volatile unsigned long delay;

	// 1) Enable clock for corresponding port
		
	switch(baseAddr)
	{
		case GPIO_PORTA_BASE :
			SYSCTL_RCGC2_R |= 1 << 0;
			delay = SYSCTL_RCGC2_R;
			break;
		
		case GPIO_PORTB_BASE :
			SYSCTL_RCGC2_R |= 1 << 1;
			delay = SYSCTL_RCGC2_R;
			break;

		case GPIO_PORTC_BASE :
			SYSCTL_RCGC2_R |= 1 << 2;
			delay = SYSCTL_RCGC2_R;
			GPIO_PORTC_LOCK_R = 0x4C4F434B;   // 1.2) unlock PortC
			GPIO_PORTC_CR_R |= digPins;          // allow changes to Port pins
			break;

		case GPIO_PORTD_BASE :
			SYSCTL_RCGC2_R |= 1 << 3;
			delay = SYSCTL_RCGC2_R;
			GPIO_PORTD_LOCK_R = 0x4C4F434B;   // 1.2) unlock PortD 
			GPIO_PORTD_CR_R |= digPins;          // allow changes to Port pins
			break;

		case GPIO_PORTE_BASE :
			SYSCTL_RCGC2_R |= 1 << 4;
			delay = SYSCTL_RCGC2_R;
			break;

		case GPIO_PORTF_BASE :
			SYSCTL_RCGC2_R |= 1 << 5;
			delay = SYSCTL_RCGC2_R;
			GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 1.2) unlock PortF
			GPIO_PORTF_CR_R |= digPins;          // allow changes to Port pins
			break;

		default :
			SYSCTL_RCGC2_R |= 1 << 0;
			delay = SYSCTL_RCGC2_R;
			break;
	}

	// 2) Set the pin direction and mode.
    HWREG(baseAddr + GPIO_PORTx_DIR_R_OFFSET) = ((pinDir & 1) ?
										        (HWREG(baseAddr + GPIO_PORTx_DIR_R_OFFSET) | digPins) :
										        (HWREG(baseAddr + GPIO_PORTx_DIR_R_OFFSET) & ~(digPins)));
    
    // 3) Clear GPIOAFSEL & GPIOPCTLregisters to set pins as GPIO 
	HWREG(baseAddr + GPIO_PORTx_AFSEL_R_OFFSET) &= ~digPins;
	HWREG(baseAddr + GPIO_PORTx_PCTL_R_OFFSET) &= ~digPins;

	// 4) Pad configuration for pull-up, pull-down, or open drain functionality (GPIOPUR, GPIOPDR, GPIOODR registers)
	switch(padConf)
	{
		case GPIO_NON :
		HWREG(baseAddr + GPIO_PORTx_PUR_R_OFFSET) &= ~digPins;
		HWREG(baseAddr + GPIO_PORTx_PDR_R_OFFSET) &= ~digPins;
		HWREG(baseAddr + GPIO_PORTx_ODR_R_OFFSET) &= ~digPins;
		break;

		case GPIO_PUR :
		HWREG(baseAddr + GPIO_PORTx_PUR_R_OFFSET) |= digPins;
		break;

		case GPIO_PDR :
		HWREG(baseAddr + GPIO_PORTx_PDR_R_OFFSET) |= digPins;
		break;

		case GPIO_ODR :
		HWREG(baseAddr + GPIO_PORTx_ODR_R_OFFSET) |= digPins;
		break;

		default :
		HWREG(baseAddr + GPIO_PORTx_ODR_R_OFFSET) &= ~digPins;
		HWREG(baseAddr + GPIO_PORTx_PDR_R_OFFSET) &= ~digPins;
		HWREG(baseAddr + GPIO_PORTx_ODR_R_OFFSET) &= ~digPins;		
		break;
	}
	
	// 5) Set the corresponding DEN bits in the GPIODEN register
	HWREG(baseAddr + GPIO_PORTx_DEN_R_OFFSET) |= digPins;

	// 6) Disable analog function
	HWREG(baseAddr + GPIO_PORTx_AMSEL_R_OFFSET) &= ~digPins;

}

void PortIOWrite(uint32_t baseAddr, uint8_t digPins, uint8_t dato)
{
	
	HWREG(baseAddr + GPIO_PORTx_DATA_R_OFFSET) = dato&digPins;
	
}

uint32_t PortIORead(uint32_t baseAddr, uint8_t digPins)
{
	
	return HWREG(baseAddr + GPIO_PORTx_DATA_R_OFFSET) & digPins;
	
}
