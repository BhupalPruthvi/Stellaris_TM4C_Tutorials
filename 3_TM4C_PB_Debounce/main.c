#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "delay.h"
int main(void)
{
  SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2);
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_4);
  while(1)
  {
      {
          uint8_t state = 0;
          uint32_t pinVal=0;  // variable to hold the pinRead
          pinVal= GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_4);    // read F4

          if(pinVal>0 && state == 0)
          {
            delay(20);
            if(pinVal>0)
            {
            GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_2, 4);    // turn on one LED
            state = 1;
            }
          }
          else if(pinVal>0 && state == 1)
          {
            delay(20);
            if(pinVal>0)
            {
            GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_2, 0);
            state = 0;
            }
          }
        }
  }
}
