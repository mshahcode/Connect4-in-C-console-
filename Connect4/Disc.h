#ifndef _DISK_H_
#define _DISK_H_


#include <stdio.h>
#include <stdlib.h>
#include "Color.h"
#include <math.h>


typedef struct Disc{
  char symbol;
  unsigned char color;
} Disc;

Disc D_new(char symbol,unsigned char color);
void D_show(Disc d);

#endif