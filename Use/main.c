#include "stm32f4xx.h"
#include "LED.h"
#include "my_time.h"
#include "i2c.h"


int main(void)
{

	LED_Init();
	Time6_Init();
	My_I2C_Init();
	
	while(1)
	{
		
	}
}


