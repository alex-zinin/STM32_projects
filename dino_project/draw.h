#pragma once

#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_ll_tim.h"
#include "stm32f0xx_ll_usart.h"
#include "xprintf.h"
#include "oled_driver.h"
#include<math.h>

void drawpixel(int x, int y);
void delpixel(int x, int y);
