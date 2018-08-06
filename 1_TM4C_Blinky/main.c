#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"bbb
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/delay.h"

uint8_t ui8PinData_1=2;
uint8_t ui8PinData_2=4;
uint8_t ui8PinData_3=8;
int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, ui8PinData_1);
        delay(1000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00);
        delay(1000);
        //----------------------------
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, ui8PinData_2);
        delay(1000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x00);
        delay(1000);
        //----------------------------
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, ui8PinData_3);
        delay(1000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
        delay(1000);
    }
}
