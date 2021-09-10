#include "Disc.h"

Disc D_new(char symbol,unsigned char color){
  Disc new_disc;
  new_disc.symbol=symbol;
  new_disc.color=color;
  return new_disc;
}


void D_show(Disc d){
  C_printChar(d.symbol, d.color, C_DEFAULT);
  printf(" ");
}