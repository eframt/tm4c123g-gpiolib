/*
 * spi_tm4c123g.h
 *
 *  Created on: 21/06/2017
 *  Author: efrain
 */

#ifndef DRVLIB_TM4C123G_H_
#define DRVLIB_TM4C123G_H_

/* Base Address for Ports */
#define UART0 0x4000C000
#define UART1 0x4000D000
#define UART2 0x4000E000
#define UART3 0x4000F000
#define UART4 0x40010000
#define UART5 0x40011000
#define UART6 0x40012000
#define UART7 0x40013000

#define SPI0 0x40008000
#define SPI1 0x40009000
#define SPI2 0x4000A000
#define SPI3 0x4000B000

#define GPIO_PORTA_BASE 0x40004000
#define GPIO_PORTB_BASE 0x40005000
#define GPIO_PORTC_BASE 0x40006000
#define GPIO_PORTD_BASE 0x40007000
#define GPIO_PORTE_BASE 0x40024000
#define GPIO_PORTF_BASE 0x40025000

#define UARTx_CTL_R_OFFSET 0x030
#define UARTx_IBRD_R_OFFSET 0x024
#define UARTx_FBRD_R_OFFSET 0x028
#define UARTx_LCRH_R_OFFSET 0x02C
#define UARTx_FR_R_OFFSET 0x018
#define UARTx_DR_R_OFFSET 0x000
#define SYSCTL_RCGCUART_Rx 0x00000001
#define SYSCTL_RCGC1_UARTx 0x00000001

#define SSIx_CR0_R_OFFSET 0x000
#define SSIx_CR1_R_OFFSET 0x004
#define SSIx_CC_R_OFFSET 0xFC8
#define SSIx_CPSR_R_OFFSET 0x010
#define SSIx_SR_R_OFFSET 0x00C
#define SSIx_DR_R_OFFSET 0x008

#define GPIO_PORTx_DATA_R_OFFSET 0x3FC
#define GPIO_PORTx_DIR_R_OFFSET 0x400
#define GPIO_PORTx_PUR_R_OFFSET 0x510
#define GPIO_PORTx_PDR_R_OFFSET 0x514
#define GPIO_PORTx_ODR_R_OFFSET 0x50C
#define GPIO_PORTx_AFSEL_R_OFFSET 0x420
#define GPIO_PORTx_AMSEL_R_OFFSET 0x528
#define GPIO_PORTx_PCTL_R_OFFSET 0x52C
#define GPIO_PORTx_DEN_R_OFFSET 0x51C
#define GPIO_PORTx_LOCK_R_OFFSET 0x520
#define GPIO_PORTx_CR_R_OFFSET 0x524

#endif /* DRVLIB_TM4C123G_H_ */
