#include<iostream>
#define size 4

using namespace std;

bool isSafe(int row,int col,int board[size][size])
{
  for(int i=0;i<col;i++)
    if(board[row][i]==1)
      return false;

  for(int i=row,j=col; i>=0 && j>=0 ; i--,j--)
    if(board[i][j]==1)
      return false;

  for(int i=row,j=col;j>=0 && i<size ; i++,j--)
    if(board[i][j]==1)
      return false;

return true;
}

void print_sol(int board[size][size])
{
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      printf("%d ",board[i][j]);
      printf("\n");
  }
}

int queen_pos(int col,int board[size][size])
{
  if(col>=size)
  return 0;

  for(int i=0;i<size;i++)
  {
    if(isSafe(i,col,board)==true)
    {
      board[i][col]=1;
      if(queen_pos(col+1,board)==0)
        return 0;

      board[i][col]=0;
    }
  }
  return 1;
}

bool place_queen()
{
  int board[size][size]={{0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}};

  if(queen_pos(0,board) == 1)
  {
      printf("solution does not exist.");
      return false;
  }

  print_sol(board);
  return true;
}

int main()
{
  place_queen();
  return 0;
}
