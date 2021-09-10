#include <stdio.h>
#include "Board.h"


int main(void) {
  printf("\n\t\t************* Welcome to Connect4 Game *************\n");

  Board board[B_ROW][B_COL];
  B_initialize(B_ROW, B_COL, board);
  B_show(B_ROW, B_COL, board);

  Disc red = D_new('O', C_RED);
  Disc yellow = D_new('O', C_YELLOW);

  int player = 1;
  int col;
  int alignment = 0;
  
  while(alignment<4){
    printf("\nDear player %d, please choose the column you want to put the tile: ",player);
    scanf("%d",&col);
    getchar();
    if(col>B_COL || col<=0 || B_iscolumnFull(B_ROW, B_COL, board,col)){
      printf("\nDear player %d, choose correct column!\n",player);
      continue;
    }
    if(player==1){B_addDisc(B_ROW, B_COL,board, &red,col);}
    if(player==2){B_addDisc(B_ROW, B_COL,board, &yellow,col);}
    B_show(B_ROW, B_COL, board);

    alignment = B_win(B_ROW, B_COL, board);

    if(alignment<4){
      if(player==1){
        player=2;
      }else{
        player=1;
      }
    }else{
      B_initialize(B_ROW, B_COL, board);
    }
  }
  printf("\nCongratulations!!! Player %d won!\n",player);
  printf("\nFarewell players!\n");
  
  return 0;
}