#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
   uint32_t nt;
   nt=UART1_ReceiveData8();
   if(nt=='a')
   {     
       GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
   }
     
}
void main(void)
{
  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_HIGH_FAST);

  UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR , ENABLE);
  UART1_Cmd(ENABLE);
   enableInterrupts();
  /* Infinite loop */
  while (1)
  {
  }

}

#ifdef USE_FULL_ASSERT


void assert_failed(u8* file, u32 line)
{

  while (1)
  {
    
  }
}
#endif
