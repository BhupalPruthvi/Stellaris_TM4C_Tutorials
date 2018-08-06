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


int main()
{
    char buffer;
    uartConsoleInit();                  //include uartConsole.h
    while(1)
    {
      buffer=UARTgetc();
      UARTprintf("%c\n\r", buffer);
    }
}


