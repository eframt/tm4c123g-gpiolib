#include "include/gpio_tm4c123.h"
#include "include/tm4c123gh6pm.h"
#include "include/hw_types.h"
#include "include/drvlib_tm4c123g.h"

int main(void)
{
	uint8_t portRead;
	
	PortIOConfig(GPIO_PORTF_BASE, 0xFF, GPIO_DIR_MODE_OUT, GPIO_NON);
	PortIOWrite(GPIO_PORTF_BASE, 0xFF, 0x1E);
	portRead = PortIORead(GPIO_PORTF_BASE, 0x02);
	
	return 0;
}
