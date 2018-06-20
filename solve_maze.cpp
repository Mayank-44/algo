#include<cstdio>
using namespace std;
#define size 4

bool isSafe(int x,int y,int maze[size][size])
{
  if(x>=0 && x<size && y>=0 && y<size && maze[x][y] == 1)
    return true;

    return false;
}

void print_sol(int sol_matrix[size][size])
{
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
      printf("%d  ",sol_matrix[i][j]);
    printf("\n");
  }
}

int find_path(int x,int y,int sol_matrix[size][size],int maze[size][size])
{
  if(x==size-1 && y==size-1)
  {
    sol_matrix[x][y]=1;
    return 0;
  }

  if(isSafe(x,y,maze)==true)
  {
    sol_matrix[x][y]=1;

    if(find_path(x+1,y,sol_matrix,maze) == 0)
    return 0;

    if(find_path(x,y+1,sol_matrix,maze) == 0)
    return 0;

    sol_matrix[x][y]=0;
    return 1;
  }
  return 1;
}

bool solve_maze(int maze[size][size])
{
  int sol_matrix[size][size];
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
      sol_matrix[i][j]=0;
  if(find_path(0,0,sol_matrix,maze)==1)
  {
      printf("Solution does not exist.");
      return false;
  }
  else
    print_sol(sol_matrix);
return true;
}

int main()
{
  int maze[size][size]={{1, 1, 0, 0},
                        {0, 1, 0, 1},
                        {0, 1, 0, 0},
                        {1, 1, 1, 1}};
  solve_maze(maze);
  return 0;
}
