#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
int main(void)
{
  SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); // set up the clock
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // enable port F
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1); // enable outputs on the launchpad LED pins

  HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY; // unlock the GPIOCR register for port F
  HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x01;

  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);    // make F4 an input
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); // enable F4's pullup, the drive strength won't affect the input
  while(1)
  {
    uint32_t pinVal=0;  // variable to hold the pinRead
    pinVal= GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0);    // read F4

    if( (pinVal & GPIO_PIN_0)==0)
    {  // AND to strip out anything but the value read from F4
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 2);    // turn on one LED
    }

    else
    {
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);    // turn on a different LED
    }
  }
}
