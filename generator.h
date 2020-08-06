
int counter;

void recurse_Sudoku(Sudoku* sudoku){
    int k = isSolvedPuzzle(sudoku);
    if (k == -1){
        counter++;
        return;
    }
    int ix = k/size;
    int jx = k-ix*size;
    int choice;
    for(choice =1;choice<=size;choice++)
    {
        if (check(sudoku,choice,ix,jx))
        {
            sudoku->vertices[ix][jx]->value = choice;
            recurse_Sudoku(sudoku);
            sudoku->vertices[ix][jx]->value = 0;
        }
    }
}

int generator_solve_Sudoku(Sudoku* sudoku)
{
    counter = 0;
    recurse_Sudoku(sudoku);
    return counter;
}