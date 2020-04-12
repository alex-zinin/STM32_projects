#include"ground.h"


void drawground()
{
  int i = 0;
  for(i = 0; i < 128; i++)
    oled_set_pix(i,55, clBlack);
}
