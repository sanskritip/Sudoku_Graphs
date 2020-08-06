void display_board(Sudoku* sudoku);
int solve_Sudoku(Sudoku* sudoku);

//NEEDS WORK.
void display_board(Sudoku* sudoku)
{	 printf("\n_________________________\n");
    int space = pow(size,0.5);
    int i,j;
    for(i=0;i<size;i++)
    {   printf("|");
    	for(j = 0;j<size;j++)
        {
            printf("%d ",sudoku->vertices[i][j]->value);
            if (j%space==space-1)
            {            
                printf(" |");
            }
        }
        if (i%space==space-1)
        {       printf("\n_________________________\n");
                
        }
        printf("\n");
    }
        
}




int solve_Sudoku(Sudoku* sudoku)
{
    int k = isSolvedPuzzle(sudoku);
    if (k == -1){
        return 1;
    }

    int ix = k/size;
    int jx = k-ix*size;
    int choice;
    for(choice =1;choice<=size;choice++)
    {
        if (check(sudoku,choice,ix,jx))
        {
            sudoku->vertices[ix][jx]->value = choice;

            if (solve_Sudoku(sudoku))
                return 1;

            sudoku->vertices[ix][jx]->value = 0;
        }
    }
    return 0;
}
