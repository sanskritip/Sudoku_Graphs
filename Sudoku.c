#include "sudoku_func.h"

void sudoku_to_array(Sudoku* sudoku, int grid[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            grid[i][j] = sudoku->vertices[i][j]->value;
        }
    }
}

void array_to_sudoku(Sudoku* sudoku, int grid[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku->vertices[i][j]->value = grid[i][j];
        }
    }
}

void generator(int grid[9][9]){
    generator_main(grid);
    printf("Generated 2D Array Puzzle with 40 empty cells \n");
    //print(grid);
    //return grid;
}

void solver(int grid[9][9]){
    Sudoku* sudoku = initialize_board(); 
    int d,i,j;
    array_to_sudoku(sudoku,grid);
    solve_Sudoku(sudoku);
    printf("Puzzle solved using graphs\n");
    display_board(sudoku);
    sudoku_to_array(sudoku,grid);
    //return grid;
}

int main(){ 
    /*int grid[9][9]={0};
    generator(grid);
    print(grid);*/
    return 0;
}