#pragma once 

#include"draw.h"


typedef struct
{
  int posx;//50;
  int posy;//65;
  int stat;
  int speed;
} cactus;

void drawcactus(cactus ct);
void cactusmove(cactus *ct);
void cactusdel(cactus ct);
