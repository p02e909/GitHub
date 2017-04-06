/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

uint8_t i=0;
uint8_t j=0;
INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
   uint8_t nt;
   nt=UART1_ReceiveData8();
   if(nt=='a')
     {
       i=i+1;
       j=i%2;
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
   if(j==0)
     GPIO_WriteHigh(GPIOB,GPIO_PIN_5);
   else
     GPIO_WriteLow(GPIOB,GPIO_PIN_5);                
  }

}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif