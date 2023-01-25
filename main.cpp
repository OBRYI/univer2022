#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
 
void delay(void);
	
int main(void)
{
  int i;
  GPIO_InitTypeDef  GPIO_InitStructure;
 
 
  // Enable PORTB Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  
  GPIO_ResetBits(GPIOB, GPIO_Pin_11); // Set B11 to Low level ("0")
 
  /* Initialize Button input PA3 */
  // Enable PORTA Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  /* Configure the GPIO_BUTTON pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  while (1) {
 
     if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) != 0) {
		 /* Toggle LED which connected to PB11*/
		 GPIOB->ODR ^= GPIO_Pin_11; // Invert B11
		 /* delay */
		void delay(void);
		 /* Toggle LED which connected to PB11*/
		 GPIOB->ODR ^= GPIO_Pin_11;
		 /* delay */
		void delay(void); }
		 else { GPIO_SetBits(GPIOB, GPIO_Pin_11); }
		GPIO_SetBits(GPIOB, GPIO_Pin_11); 
		void delay(void);
		GPIO_ResetBits(GPIOB, GPIO_Pin_11); 
		void delay(void);
		GPIOB->ODR&=~GPIO_Pin_11;
		void delay(void);
		GPIOB->ODR|=GPIO_Pin_11;
		void delay(void);

  }
}
