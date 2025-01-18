#ifndef __I2C__H
#define __I2C__H

#include "stm32f4xx.h"

#define I2C_SCL_IO_CLK RCC_AHB1Periph_GPIOB 
#define I2C_SDA_IO_CLK RCC_AHB1Periph_GPIOB 

#define I2C_SCL_PIN  GPIO_Pin_8
#define I2C_SDA_PIN  GPIO_Pin_9




void My_I2C_Init(void);

#endif
