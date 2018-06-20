#include<stdio.h>

#define size 8

bool isSafe(int x, int y, int grid[size][size])
{
    return ( x >= 0 && x < size && y >= 0 && y < size && grid[x][y] == -1);
}


void printsolution(int grid[size][size])
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
            printf(" %2d ", grid[x][y]);
        printf("\n");
    }
}

int fill_grid(int x, int y, int move_i, int grid[size][size],int xMove[size], int yMove[size])
{
   int next_x, next_y;

   if (move_i == size*size)
       return 0;

   for (int i = 0; i < 8; i++)
   {
       next_x = x + xMove[i];
       next_y = y + yMove[i];

       if (isSafe(next_x, next_y, grid))
       {
         grid[next_x][next_y] = move_i;
         if (fill_grid(next_x, next_y, move_i+1, grid,xMove, yMove) == 0)
             return 0;
         else
             grid[next_x][next_y] = -1;// backtracking
       }
   }

   return 1;
}

bool solve_knight()
{
    int grid[size][size];

    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            grid[x][y] = -1;

    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    grid[0][0]  = 0;

    if (fill_grid(0, 0, 1, grid, xMove, yMove) == 1)
    {
        printf("solution does not exist");
        return false;
    }
    else
        printsolution(grid);

    return true;
}

int main()
{
    solve_knight();
    return 0;
}
