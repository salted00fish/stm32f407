#include "my_time.h"

unsigned int Time_Cunt = 0;


void Time6_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_InitStruct;
    NVIC_InitTypeDef    NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);

    TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStruct.TIM_Period = 1000-1;
    TIM_InitStruct.TIM_Prescaler = 84-1; 
    TIM_InitStruct.TIM_RepetitionCounter = 0;

    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
    TIM_TimeBaseInit(TIM6,&TIM_InitStruct);
    TIM_Cmd(TIM6,ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    //NVIC_EnableIRQ(TIM6_DAC_IRQn);

    NVIC_Init(&NVIC_InitStructure);
}


unsigned int Get_Time_Count(void)
{
    return Time_Cunt;
}


void TIM6_DAC_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM6,TIM_IT_Update) == SET)
    {
        Time_Cunt++;
        TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
    }
}
