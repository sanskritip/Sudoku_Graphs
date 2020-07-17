#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "sudoku_func.h"


int main()
{
    Sudoku* sudoku = initialize_board(); 
    int d,i,j;
    FILE *fp;
    fp = fopen(puzzle,"r");

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            fscanf(fp,"%d",&d);
            sudoku->vertices[i][j]->value = d;
        }
    }
    printf("\n PUZZLE :\n");
    display_board(sudoku);

    if(solve_Sudoku(sudoku))
    {
        printf("\n SOLUTION :\n");
        display_board(sudoku);
    }
    else
    {
        printf("No solution exists..");
    }
}