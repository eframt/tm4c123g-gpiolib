#ifndef __GPIO_TM4C123_H__
#define __GPIO_TM4C123_H__

#include <stdint.h>

//*****************************************************************************
//
// Values that can be passed to PortIOConfig as the pinDir parameter that
// correspond to INPUT and OUTPUT functionality.
//
//*****************************************************************************
#define GPIO_DIR_MODE_IN  0x00  // Pin is a GPIO input
#define GPIO_DIR_MODE_OUT 0x01  // Pin is a GPIO output

//*****************************************************************************
//
// Values that can be passed to PortIOConfig as the padConf parameter that
// correspond to PUR, PDR, ODR, or none.
//
//*****************************************************************************
#define GPIO_NON 0x00
#define GPIO_PUR 0x01
#define GPIO_PDR 0x02
#define GPIO_ODR 0x03

void PortIOConfig(uint32_t baseAddr, uint8_t digPins, uint8_t pinDir, uint8_t padConf);

void PortIOWrite(uint32_t baseAddr, uint8_t digPins, uint8_t dato);

uint32_t PortIORead(uint32_t baseAddr, uint8_t digPins);

#endif //__GPIO_TM4C123_H__
