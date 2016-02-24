/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_conf.h"
#include "stm32f10x.h"
#include "lcd.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

u8 *c1 = StringTest1;
u8 *c2 = StringTest2;

/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
//void LongDelay(__IO uint32_t nCount);
void LongDelay(u32 nCount);


/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : main.
* Description    : Main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int main(void)
{

#ifdef DEBUG
  debug();
#endif

  SystemInit();
 
  /* Enable FSMC, GPIOD, GPIOE, GPIOF, GPIOG and AFIO clocks */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE |
                         RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG |
                         RCC_APB2Periph_AFIO, ENABLE);
  
  STM3210E_LCD_Init(); 
  LCD_Clear();
  
  //Enable Key 1
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  //LCD_DrawChar(0, 0, 'a'); 	// Display a
  //LCD_DrawChar(4, 104, 'b'); 	// Dispaly b 
  while (1) {
    
    while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){};
  /* Task 1: Write your name on LCD */
    LCD_Clear();
    LCD_DrawString(0, 0, "yu chendi", 9);
    LCD_DrawString(2, 0, "dai yangyang", 12);
    
  
  // Verify Task 2: Draw a cross
    LCD_Clear();
    LCD_DrawDot(0, 0);
    LCD_DrawDot(0, 127);
    LCD_DrawDot(63, 0);
    LCD_DrawDot(63, 127);
    LCD_DrawDot(32, 64);
    int i = 5;
    while(i--){
      LCD_DrawDot(32 + i, 64 + i);
      LCD_DrawDot(32 + i, 64 - i);
      LCD_DrawDot(32 - i, 64 + i);
      LCD_DrawDot(32 - i, 64 - i);
    }
  
  // Verify Task 3: Draw a vertical line
    LCD_Clear();
    LCD_DrawDot(0, 0);
    LCD_DrawDot(1, 0);
    LCD_DrawDot(2, 0);
    LCD_DrawDot(3, 0);
    LCD_DrawDot(4, 0);
  }
 
}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/* DELAY  */

//void LongDelay(__IO uint32_t nCount)
void LongDelay(u32 nCount)
{
  for(; nCount != 0; nCount--);
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
