#include "i2c.h"


static void I2C_IO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(I2C_SCL_IO_CLK|I2C_SDA_IO_CLK,ENABLE);
    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStruct.GPIO_Pin = I2C_SCL_PIN|I2C_SDA_PIN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB,&GPIO_InitStruct);
    
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_I2C1);
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_I2C1);
}


void My_I2C_Init(void)
{
    I2C_InitTypeDef I2C_InitStruct;

    I2C_IO_Init();

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
    
    I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;  
    I2C_InitStruct.I2C_ClockSpeed = 100000;         //配置时钟速度为100K的标志速度I2C
    I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStruct.I2C_OwnAddress1 = 0x00;  // 设置自身设备地址

    I2C_Init(I2C1,&I2C_InitStruct);
    I2C_Cmd(I2C1,ENABLE);
}


