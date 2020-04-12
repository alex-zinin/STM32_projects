/*
 * This example demonstrates using timers as counters
 */

#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_ll_tim.h"
#include "stm32f0xx_ll_usart.h"
#include "xprintf.h"
#include "oled_driver.h"
#include <math.h>
#include"draw.h"
#include"dino.h"
#include"cactus.h"
#include"ground.h"

/**
  * System Clock Configuration
  * The system Clock is configured as follow :
  *    System Clock source            = PLL (HSI/2)
  *    SYSCLK(Hz)                     = 48000000
  *    HCLK(Hz)                       = 48000000
  *    AHB Prescaler                  = 1
  *    APB1 Prescaler                 = 1
  *    HSI Frequency(Hz)              = 8000000
  *    PLLMUL                         = 12
  *    Flash Latency(WS)              = 1
  */

  speed = 100;
  static int statusg = 1;
  static void set_indicator(uint8_t number);
  static  uint32_t number = 1;
  static uint8_t coun = 0;
  static int frequency = 4;


static void rcc_config()
{
    /* Set FLASH latency */
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);

    /* Enable HSI and wait for activation*/
    LL_RCC_HSI_Enable();
    while (LL_RCC_HSI_IsReady() != 1);

    /* Main PLL configuration and activation */
    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI_DIV_2,
                                LL_RCC_PLL_MUL_12);

    LL_RCC_PLL_Enable();
    while (LL_RCC_PLL_IsReady() != 1);

    /* Sysclk activation on the main PLL */
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL);

    /* Set APB1 prescaler */
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);

    /* Update CMSIS variable (which can be updated also
     * through SystemCoreClockUpdate function) */
    SystemCoreClock = 48000000;
}

/*
 * Clock on GPIOC and set two led pins
 */



static void gpio_config(void)
{

      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_0, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);


      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_9, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_10, LL_GPIO_MODE_OUTPUT);



      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
      LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_12, LL_GPIO_MODE_INPUT);


      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
      LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
      LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_9, LL_GPIO_MODE_OUTPUT);

      LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_12, LL_GPIO_PULL_DOWN);

    return;
}



void flash(uint32_t number)
{

  if(coun % frequency == 0)
  {
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_9);
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_8);
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_7);


    set_indicator(number%10);

  }

  if(coun % frequency == 1)
  {
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_10);
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_9);

    set_indicator((uint8_t)(number%100)/10);


  }


  if(coun % frequency == 2)
    {

      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);
      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);
      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_7);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_9);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_10);

    set_indicator((number%1000)/100);

    }


    if(coun % frequency == 3)
    {

      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_9);
      LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_8);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_9);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_10);
      LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_7);

      set_indicator(number/1000);

    }

}

typedef struct
{
  int posx;//50;
  int posy;//65;
  int stat;

}cloud;



void drawcloud(cloud clo)
{

  int i = 0;
    int j = 0;
    int ps = clo.posx;
    int gr = clo.posy;
        for(i = 0; i < 16; i++)
      {
          drawpixel(ps+2*i, gr);
      }
      for(i = 0; i < 12; i++)
    {
        drawpixel(ps+2*i, gr-15);
    }

    drawpixel(ps+30+2, gr-2);
    drawpixel(ps+30+4, gr-4);
    drawpixel(ps+30+4, gr-6);
    drawpixel(ps+30+2, gr-8);
    drawpixel(ps+30, gr-10);
    drawpixel(ps+28, gr-12);
    drawpixel(ps+26, gr-14);
    drawpixel(ps+24, gr-16);


    drawpixel(ps-2, gr-2);
    drawpixel(ps-4, gr-4);
    drawpixel(ps-4, gr-6);
    drawpixel(ps-2, gr-8);
    drawpixel(ps, gr-10);
    drawpixel(ps-2, gr-12);
    drawpixel(ps-4, gr-14);
    drawpixel(ps-2, gr-16);


}

void movecloud(cloud* clo)
{
  clo->posx = clo->posx - 1;
  if(clo->posx < -25)
    clo->posx = 160;

}

void delcloud(cloud clo)
{
  int i = 0;
    int j = 0;
    int ps = clo.posx;
    int gr = clo.posy;
        for(i = 0; i < 16; i++)
      {
          delpixel(ps+2*i, gr);
      }
      for(i = 0; i < 12; i++)
    {
        delpixel(ps+2*i, gr-15);
    }

    delpixel(ps+30+2, gr-2);
    delpixel(ps+30+4, gr-4);
    delpixel(ps+30+4, gr-6);
    delpixel(ps+30+2, gr-8);
    delpixel(ps+30, gr-10);
    delpixel(ps+28, gr-12);
    delpixel(ps+26, gr-14);
    delpixel(ps+24, gr-16);


    delpixel(ps-2, gr-2);
    delpixel(ps-4, gr-4);
    delpixel(ps-4, gr-6);
    delpixel(ps-2, gr-8);
    delpixel(ps, gr-10);
    delpixel(ps-2, gr-12);
    delpixel(ps-4, gr-14);
    delpixel(ps-2, gr-16);
}
static void set_indicator(uint8_t number)
{
    /*
     * Put all pins for indicator together (for segments only)
     */
    static uint32_t mask = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | \
                           LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | \
                           LL_GPIO_PIN_6;
    /*
     * For simplicity there are only decoded values for the first 4 numbers
     */
    static const uint32_t decoder[] = {
        LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | \
        LL_GPIO_PIN_4 | LL_GPIO_PIN_5, // 0
        LL_GPIO_PIN_1 | LL_GPIO_PIN_2, // 1
        LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_6 | LL_GPIO_PIN_4 | \
        LL_GPIO_PIN_3, // 2
        LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_6 | LL_GPIO_PIN_2 | \
        LL_GPIO_PIN_3, // 3
        LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2, // 4
        LL_GPIO_PIN_0 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | \
        LL_GPIO_PIN_6 | LL_GPIO_PIN_5,// 5
        LL_GPIO_PIN_4 | LL_GPIO_PIN_0 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | \
        LL_GPIO_PIN_6 | LL_GPIO_PIN_5,//6
        LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2, // 7
        LL_GPIO_PIN_4 | LL_GPIO_PIN_0 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | \
        LL_GPIO_PIN_6 | LL_GPIO_PIN_5 | LL_GPIO_PIN_1,// 8
        LL_GPIO_PIN_0 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | \
        LL_GPIO_PIN_6 | LL_GPIO_PIN_5 | LL_GPIO_PIN_1, // 9


    };
    const uint8_t max_num = sizeof(decoder) / sizeof(uint32_t);
    uint32_t port_state = 0;

    /*
     * Read current state and do not change pins that are not related to
     * indicator (that is done by using masking)
     */
   // LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_11);
    port_state = LL_GPIO_ReadOutputPort(GPIOA);
    /*
     * Example:
     * 01100101 <= Input
     * mask = 111 (pins allowed to be changed)
     * ~mask = 11111000 (inverted mask sets remaing bits to one)
     * result = result & ~mask (zero only first three bits)
     * result = result | 001 (modify first three bits)
     * result -> 01100001
     */
   // LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_11);
    port_state = (port_state & ~mask) | decoder[number % max_num];
    LL_GPIO_WriteOutputPort(GPIOA, port_state);
    return;
}
/*
 * Configure timer to counter mode
 */
static void timers_config(void)
{
    /*
     * Setup timer
     */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
    LL_TIM_SetPrescaler(TIM2, 999);
    LL_TIM_SetAutoReload(TIM2, 99);
    LL_TIM_SetCounterMode(TIM2, LL_TIM_COUNTERMODE_UP);
    LL_TIM_EnableIT_UPDATE(TIM2);
    LL_TIM_EnableCounter(TIM2);
    /*
     * Setup NVIC
     */
    NVIC_EnableIRQ(TIM2_IRQn);
    NVIC_SetPriority(TIM2_IRQn, 0);
    return;
}

void TIM2_IRQHandler(void)
{
    LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_8);
    flash(number);
    coun  = coun+1;
    if(coun %20 == 0 && statusg != 0)
    number = number +1;
    if(number %10 == 0)
    //speed = speed + 100;
    LL_TIM_ClearFlag_UPDATE(TIM2);
}

void fgameover()
{
  oled_clr(clBlack);

  //  number = 0;
    frequency = 4;
    statusg  = 0;

    xprintf("\n     Game over\n");
    xprintf("\n    Try again\n");
    xprintf("\n    PUSH RESET\n\n");
while(1)
{



    //  xprintf("Game over");

    oled_update();}
}

static void printf_config(void)
{
   xdev_out(oled_putc);
   return;
}


int main(void)
{
    rcc_config();
    gpio_config();
    timers_config();
    oled_config();
    printf_config();


    cloud clo;
    clo.posx = 60;
    clo.posy = 20;

    // xprintf("\n     Hello, world!\n\n");
    // xprintf("    This is an OLED\n");
    // xprintf("   display based on\n");
    // xprintf("    SSD1306 driver");
    oled_update();
    oled_clr(clWhite);
    int i = 0;
    //oled_set_pix(0,0, clBlack);
    drawground();
  //  drawdino1(50, 65);
    cactus ct;
    ct.posx = 120;
    ct.posy = 60;
    ct.speed = 1;
    drawcactus(ct);
    dino dn;
    dn.posx = 40;
    dn.posy = 65;
    //drawdino1(dn.posx, dn.posy);
    int stat = 0;
    int fl = 1;
    int jump = 0;
    uint32_t debouncer_clk = 0;
    uint32_t button_pressed = 0;
      int gameover = 0;
    while(1)
    {
      if(number%500 == 0)
       ct.speed = ct.speed + 1;
      if(gameover == 1)
        {
          break;}
      if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
        {
          gameover = 1;
          fgameover();
            break;
        }


      delcloud(clo);
      cactusdel(ct);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      dinoanimation1(dn);
      cactusmove(&ct);
      movecloud(&clo);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

    //  delcloud(clo);
      cactusdel(ct);
      delcloud(clo);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      dinoanimation1(dn);
      cactusmove(&ct);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

      cactusdel(ct);
      delcloud(clo);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      cactusmove(&ct);
      movecloud(&clo);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

      cactusdel(ct);
      delcloud(clo);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      dinoanimation2(dn);
      cactusmove(&ct);
      movecloud(&clo);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

      cactusdel(ct);
      delcloud(clo);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      dinoanimation2(dn);
      cactusmove(&ct);
      movecloud(&clo);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

      cactusdel(ct);
      delcloud(clo);
      dinodel(dn);
      drawground();
      drawdino1(dn);
      cactusmove(&ct);
      movecloud(&clo);
      drawcactus(ct);
      drawcloud(clo);
      oled_update();

      if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
        {
          gameover = 1;
          fgameover();
          break;
        }
      #if defined(TURN_ON_CONTACT_DEBOUNCER)
              /*
               * if button is pressed then set flag and reset counter
               */
              if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_12)) {
                  button_pressed = 1;
                  debouncer_clk = 0;
                  number = button_pressed;
              }
              /*
               * if flag is set increase counter
               */
              if (button_pressed) {
                  debouncer_clk++;
                  //delay_10ms();
              }
              /*
               * If counter manages to count up to 5 then button is not bouncing
               * any longer and we need to get action! (process it)
               * NOTE: 5 is just experimental value
               */
              if (debouncer_clk >= 5) {
                //  LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_8);
                  //number++;
                  while(1)
                  {
                  if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
                      {
                        gameover = 1;
                        fgameover();
                        break;
                      }
                     if(stat % 30 == 0)
                     fl = -fl;
                    if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
                       {
                         gameover = 1;
                         fgameover();
                         break;
                       }
                       dinodel(dn);
                       dinojump(fl, &dn);
                       cactusdel(ct);
                       delcloud(clo);
                         drawground();
                         cactusmove(&ct);
                         movecloud(&clo);
                         drawdino1(dn);
                         drawcactus(ct);
                         drawcloud(clo);
                           oled_update();
                        if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
                             {
                               gameover = 1;
                               fgameover();
                               break;
                             }
                         stat = stat+1;

                           if(dn.posy >= 65)
                             {
                               fl = 1;
                               jump = 0;
                               stat = 0;
                               button_pressed = 0;
                               break;
                             }

                         }
                  //set_indicator(number);
                  button_pressed = 0;
                  debouncer_clk = 0;
              }
      #else
              if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_12)) {
                  LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_8);
                  //number++;
                  while(1)
                  {
                     if(stat % 30 == 0)
                     fl = -fl;
                  if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
                       {
                         gameover = 1;
                         fgameover();
                         break;
                       }
                       dinodel(dn);
                       dinojump(fl, &dn);
                       cactusdel(ct);
                       delcloud(clo);
                         drawground();
                         cactusmove(&ct);
                         movecloud(&clo);
                         drawdino1(dn);
                         drawcactus(ct);
                         drawcloud(clo);
                           oled_update();
                           if((dn.posy-ct.posy)*(dn.posy-ct.posy)+(dn.posx-ct.posx)*(dn.posx-ct.posx) <= 50)
                             {
                               gameover = 1;
                               fgameover();
                               break;
                             }
                         stat = stat+1;

                           if(dn.posy >= 65)
                             {
                               fl = 1;
                               jump = 0;
                               stat = 0;
                               button_pressed = 0;

                               break;
                             }

                         }

              }
      #endif
      }
  oled_clr(clBlack);

  //  number = 0;
    frequency = 4;
    statusg  = 0;

    xprintf("\n     Game over\n");
      xprintf("\n    Try again\n");
      xprintf("\n    PUSH RESET\n\n");


    //  xprintf("Game over");

    oled_update();



    return 0;
}
