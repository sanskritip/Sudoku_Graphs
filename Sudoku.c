#include "sudoku_func.h"
int main(){
    int grid[9][9]={0};
    generator_main(grid);
    printf("Generated 2D Array Puzzle with 40 empty cells \n");
    print(grid);
    Sudoku* sudoku = initialize_board(); 
    int d,i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            sudoku->vertices[i][j]->value = grid[i][j];
        }
    }
    solve_Sudoku(sudoku);
    printf("Puzzle solved using graphs\n");
    display_board(sudoku);

    return 0;
}
