#include "stm32f10x.h"                  // Device header


int main(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;        
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;       
  RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;       
   
  GPIOA->CRL = 0x88; // PA0, PA1 input mode
  GPIOA->ODR = 0x03; // PA0, PA1 PU

  GPIOB->CRH = (GPIO_CRH_MODE13_1 | GPIO_CRH_CNF13_1 |  //PB13 TIM1_CH1N
                GPIO_CRH_MODE14_1 | GPIO_CRH_CNF14_1 |  //PB14 TIM1_CH2N
                GPIO_CRH_MODE15_1 | GPIO_CRH_CNF15_1);  //PB15 TIM1_CH3N

  // PWM Timer 1  
  TIM1->CR1 = TIM_CR1_ARPE;  
  TIM1->PSC = 7200;  
  TIM1->ARR = 1500;  
  TIM1->CCR1 = 100;  
  TIM1->CCR2 = 1000;  
  TIM1->CCR3 = 0x00;  
   
  TIM1->CCMR1 = (TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M |
                 TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M);  
  TIM1->CCER = (TIM_CCER_CC1NE | TIM_CCER_CC1NP |                           
                TIM_CCER_CC2NE |TIM_CCER_CC2NP|                           
                TIM_CCER_CC3NE |TIM_CCER_CC3NP);  
  TIM1->BDTR = (TIM_BDTR_MOE );  
  TIM1->CR1 |= TIM_CR1_CEN;
  
  int TimPulse = TIM1->CCR1;
  int i;
        while(1)
    {
      if (!(GPIOA->IDR &(1<<0))) {
        if (TimPulse < 1500) TimPulse++; 
        TIM1->CCR1 = TimPulse;

      }
      if (!(GPIOA->IDR &(1<<1))) {
        if (TimPulse > 10)  TimPulse--;
        TIM1->CCR1 = TimPulse;
      }
         // delay
         for(i=0;i<0x10000;i++);
    }
}