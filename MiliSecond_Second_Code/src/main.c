#include "stm32f4xx.h"
#include "delay_my.h"		// included our delay library


void RCC_Config(void)						// 168MHz clock config
{
	RCC->CR |= 0x00010000;                 // HSEON ENABLE
	while(!(RCC->CR & 0x00020000));        // HSEON Ready Flag wait
	RCC->CR |= 0x00080000;              // CSS ENABLE
	RCC->PLLCFGR |= 0x00400000;        // PLL SRC HSE secildi
	RCC->PLLCFGR |= 0x00000004;       // PLL M 4
	RCC->PLLCFGR |= 0x00005A00;        // PLL N 168
	RCC->PLLCFGR |= 0x00000000;       // PLL P 2
	RCC->CFGR |= 0x00000000;          // AHB PRESCALER 1
	RCC->CFGR |= 0x00080000;          // APB2 PRESCALER 2
	RCC->CFGR |= 0x00001400;          // APB1 PRESCALER 4
	RCC->CIR |= 0x00080000;             // HSE READY FLAG CLEAR
	RCC->CIR |= 0x00800000;             // CSS FLAG CLEAR
}

void GPIO_Config(void)					// D12,D13,D14,D15 user led config
{
	RCC->AHB1ENR |= (1 << 3);

	GPIOD->MODER |=	(1 << 24);
	GPIOD->MODER &= ~(1 << 25);
	GPIOD->MODER |=	(1 << 26);
	GPIOD->MODER &= ~(1 << 27);
	GPIOD->MODER |=	(1 << 28);
	GPIOD->MODER &= ~(1 << 29);
	GPIOD->MODER |=	(1 << 30);
	GPIOD->MODER &= ~(1 << 31);

	GPIOD->OSPEEDR |= 0xFF000000;

}

int main(void)
{
	NVIC_EnableIRQ(SysTick_IRQn);				// enable system tick interrupt
	RCC_Config();
	GPIO_Config();
	SysTick_Config(SystemCoreClock/1000);		// for example our clock speed 168 000 000Hz
	  	  	  	  	  	  	  	  	  	  	  	// (168 000 000) / 1000 = 168000 = counter
	  	  	  	  	  	  	  	  	  	  	  	// (1 / 168 000 000)s * 168000 = 1ms = every interrupt loop time

  while (1)
  {
	  GPIOD->ODR ^= (1 << 12); 	// toogle the GPIOD 12 pin
	  delay_my_s(1);		// our delay function ( wait 1 second)
	  //delay_my_ms(1000);  // same
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
