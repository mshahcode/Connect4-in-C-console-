#include "Board.h"

Board B_newCell(int row, int col,Disc* d){
  Board new_cell;
  new_cell.row=row;
  new_cell.col=col;
  new_cell.disc=d;
  return new_cell;
}


void B_initialize(int b_row, int b_col,Board board[][b_col]){
  for(int i = 0 ; i < b_row; i++){
    for(int j = 0 ; j < b_col; j++){
      board[i][j].row=i;
      board[i][j].col=j;
      board[i][j].disc=NULL;
    }
  }
}

void B_show(int b_row,int b_col,Board board[][b_col]){
  printf("\n\t");
  for(int i = 1 ; i <= b_col ; i++){printf("%d ",i);}
  printf("\n");
  int r = b_row;
  for(int i = 0;i<b_row;i++){
    printf(" %d\t",i+1);
    
    for(int j = 0; j < b_col;j++){
      if(board[i][j].disc==NULL){
        printf("— ");
      }else{
        D_show(*(board[i][j].disc));
      }
    }
    printf(" %d\t",i+1);
    printf("\n");
  }
  printf("\t");
  for(int i = 1 ; i <= b_col ; i++){printf("%d ",i);}
  printf("\n");
}

int B_iscolumnFull(int b_row,int b_col,Board board[][b_col],int col){
  if(col>b_col || col<=0){
    printf("Wrong column input!\n");
    return -1;
  }
  int flag = 1;
  for(int i = 0 ; i < b_row;i++){
    if(board[i][col-1].disc==NULL){
      flag=0;
    }
  }
  if(flag==1){
    return 1;
  }
  return 0;
}

void B_addDisc(int b_row,int b_col,Board board[][b_col],Disc* disc,int col){
  if(B_iscolumnFull(b_row, b_col, board, col)!=1){
    for(int i=b_row-1;i>=0;i--){
      if(board[i][col-1].disc==NULL){
        board[i][col-1].disc=disc;
        break;
      }
    }
  }else{
    printf("\nThe column is full! Can't add disc (B_addDisc)\n");
  }
}

int B_countDiscsVertical(int b_row,int b_col,Board board[][b_col],int row,int col){
  if(board[row-1][col-1].disc==NULL){
    return 0;
  }
  int count = 1;
  
  for(int i=row-1;i>=1;i--){
    if(board[i-1][col-1].disc!=NULL){
      if(board[i][col-1].disc->color==board[i-1][col-1].disc->color){
        count++;
      }else{
        break;
      }
    }else{
      break;
    }
  }

  for(int i=row-1;i<b_row-1;i++){
    if(board[i+1][col-1].disc!=NULL){
      if(board[i][col-1].disc->color==board[i+1][col-1].disc->color){
        count++;
      }else{
        break;
      }
    }else{
      break;
    }
  }
  return count;
}

int B_countDiscsHorizontal(int b_row,int b_col,Board board[][b_col],int row,int col){
  if(board[row-1][col-1].disc==NULL){
    return 0;
  }
  int count = 1;
  
  for(int i=col-1;i>=1;i--){
    if(board[row-1][i-1].disc!=NULL){
      if(board[row-1][i].disc->color==board[row-1][i-1].disc->color){
        count++;
      }else{
        break;
      }
    }else{
      break;
    }
  }
  for(int i=col-1;i<b_col;i++){
    if(board[row-1][i+1].disc!=NULL){
      if(board[row-1][i].disc->color==board[row-1][i+1].disc->color){
        count++;
      }else{
        break;
      }
    }else{
      break;
    }
  }
  return count;
}

int B_countDiscsDiagonal(int b_row,int b_col,Board board[][b_col],int row,int col){
  if(board[row-1][col-1].disc==NULL){
    return 0;
  }
  int count = 1;
  int c = col-1;
  
  for(int i = row-1;i>0;i--){
    if(c+1<=6){
      if(board[i-1][c+1].disc!=NULL){
        if(board[i][c].disc->color==board[i-1][c+1].disc->color){
          count++;
          c++;
        }else{
          break;
        }
      }else{
        break;
      }
    }else{break;}
  }
  
  c = col-1;
  for(int i=row-1;i<b_row-1;i++){
    if(c-1>=0){
      if(board[i+1][c-1].disc!=NULL){
        if(board[i][c].disc->color==board[i+1][c-1].disc->color){
          count++;
          c--;
        }else{
          break;
        }
      }else{
        break;
      }
    }else{break;}
  }
  return count;
}

int B_countDiscsTotal(int b_row,int b_col,Board board[][b_col],int row,int col){
  if(board[row-1][col-1].disc==NULL){
    return 0;
  }
  int answer;
  int vertical = B_countDiscsVertical(b_row, b_col, board, row, col);
  int horizontal = B_countDiscsHorizontal(b_row, b_col, board, row, col);
  int diagonal = B_countDiscsDiagonal(b_row, b_col, board, row, col);
  int leftDiagonal = B_countDiscsLeftDiagonal(b_row,b_col,board, row, col);
  if(vertical>=horizontal){answer=vertical;}else{answer=horizontal;};
  if(diagonal>=answer){answer=diagonal;}
  if(leftDiagonal>=answer){answer=leftDiagonal;}
  return answer;
}

int B_win(int b_row,int b_col,Board board[][b_col]){
  int max = 0;
  int score;
  for(int i = 1; i <= b_row;i++){
    for(int j = 1 ; j <= b_col;j++){
      score = B_countDiscsTotal(b_row, b_col, board,i, j);
      if(score>max){
        max=score;
      }
    }
  }
  return max;
}

int B_countDiscsLeftDiagonal(int b_row,int b_col,Board board[][b_col],int row,int col){
  if(board[row-1][col-1].disc==NULL){
    return 0;
  }
  int count = 1;
  int c = col-1;
  for(int i = row-1;i>0;i--){
    if(c-1>=0){
      if(board[i-1][c-1].disc!=NULL){
        if(board[i][c].disc->color==board[i-1][c-1].disc->color){
          count++;
          c--;
        }else{
          break;
        }
      }else{
        break;
      }
    }else{break;}
  }
  c = col-1;
  for(int i=row-1;i<b_row-1;i++){
    if(c+1<=6){
      if(board[i+1][c+1].disc!=NULL){
        if(board[i][c].disc->color==board[i+1][c+1].disc->color){
          count++;
          c++;
        }else{
          break;
        }
      }else{
        break;
      }
    }else{break;}
  }
  return count;
}