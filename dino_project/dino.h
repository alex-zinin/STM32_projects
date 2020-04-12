#pragma once

#include"draw.h"


typedef struct
{
  int posx;//50;
  int posy;//65;
  int stat;
} dino;


void drawdino1(dino dn);
void dinojump(int stat, dino *dn);
void dinoanimation2(dino dn);
void dinodel(dino dn);
void dinoanimation1(dino dn);
