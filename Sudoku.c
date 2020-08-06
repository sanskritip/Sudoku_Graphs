#include "sudoku_func.h"
int main(){
    int grid[9][9]={0};
    generator_main(grid);
    print(grid);
    return 0;
}
