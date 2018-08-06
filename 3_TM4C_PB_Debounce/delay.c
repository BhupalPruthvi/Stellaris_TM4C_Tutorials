#include "driverlib/delay.h"
#include "inc/hw_ints.h"

void delay(unsigned long ulValue)
{
    unsigned long i;
	for(i=0;i<ulValue*2*1600;i++);
}



