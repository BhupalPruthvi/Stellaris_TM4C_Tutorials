
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "utils/uartstdio.c"
#include "uartconsole.h"
#include <string.h>
#include "delay.h"

void LEDsetup();

int main()
{
    char inputVal;
    LEDsetup();
    uartConsoleInit();                  //include uartConsole.h
    while(1)
    {
      inputVal=UARTgetc();
      UARTprintf("Typed: %c\n\r", inputVal);
      switch(inputVal)
      {
          case 'r':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
              break;
          case 'b':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
              break;
          case 'g':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
              break;
          case 'R':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
              break;
          case 'B':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
              break;
          case 'G':
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
              break;
          default:
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
              break;
      }
    }
}

void LEDsetup()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
}
