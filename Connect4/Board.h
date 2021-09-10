#ifndef _BOARD_H_
#define _BOARD_H_


#include <stdio.h>
#include <stdlib.h>
#include "Disc.h"

#define B_ROW 6
#define B_COL 7



typedef struct Board{
  int row,col;
  Disc* disc;
} Board;

Board B_newCell(int row, int col,Disc* d);
void B_initialize(int b_row, int b_col,Board board[][b_col]);
void B_show(int b_row,int b_col,Board board[][b_col]);
int B_iscolumnFull(int b_row,int b_col,Board board[][b_col],int col);
void B_addDisc(int b_row,int b_col,Board board[][b_col],Disc* disc,int col);
int B_countDiscsHorizontal(int b_row,int b_col,Board board[][b_col],int row,int col);
int B_countDiscsVertical(int b_row,int b_col,Board board[][b_col],int row,int col);
int B_countDiscsDiagonal(int b_row,int b_col,Board board[][b_col],int row,int col);
int B_countDiscsTotal(int b_row,int b_col,Board board[][b_col],int row,int col);
int B_win(int b_row,int b_col,Board board[][b_col]);
int B_countDiscsLeftDiagonal(int b_row,int b_col,Board board[][b_col],int row,int col);

#endif