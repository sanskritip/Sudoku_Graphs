#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define size 9
#define puzzle "./q3.txt"
#define link_no 20
//DISPLAY FUNCTION NEEDS WORK
typedef struct Cell
{
    int value;
    struct Cell** links;
}Cell;

typedef struct Sudoku
{
    Cell* vertices[size][size];

}Sudoku;

Cell* create_cell();
void add_edge(Cell* source,Cell* target);
Sudoku* initialize_board();
void display_board(Sudoku* sudoku);
int isSolvedPuzzle(Sudoku* sudoku);
int check(Sudoku* sudoku,int choice,int i,int j);
int solve_Sudoku(Sudoku* sudoku);

Cell* create_cell()
{
    Cell* cell = malloc(sizeof(Cell));
    cell->value = 0;
    cell->links = malloc(sizeof(Cell*)*link_no);
    int i;
    for(i=0;i<link_no;i++) 
    {
        cell->links[i] = NULL;
    }
    return cell;
}

void add_edge(Cell* source,Cell* target)
{   int i;
    for (i=0;i<link_no;i++)
    {
        if (target==source) continue;
        if (source->links[i] == NULL)
        {
            source->links[i] = target;
            break;
        }
        else if (source->links[i]==target) break; 
    }
}

Sudoku* initialize_board()
{
    Sudoku* sudoku  = malloc(sizeof(Sudoku));
    int i,j,k;
    for (i=0;i<size;i++)
    {
        for(j =0;j<size;j++)
            sudoku->vertices[i][j] = create_cell(i*size+j);
    }
    for (i=0;i<size;i++)
    {
        for(j =0;j<size;j++)
        {
            Cell* ptr = sudoku->vertices[i][j];
            for(k=0;k<size;k++){
                if (k!=j)
                    add_edge(ptr,sudoku->vertices[i][k]);
                if (k!=i)
                    add_edge(ptr,sudoku->vertices[k][j]);
            }

            int sq = pow(size,0.5);
            int ix = i-i%sq;
            int jx = j-j%sq;
            int o,p;
            for(o = ix; o < ix+sq; o++){
                for(p = jx; p < jx+sq; p++){
                    add_edge(ptr,sudoku->vertices[o][p]);
                }
            }
        }
    }
    return sudoku;

}

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

int isSolvedPuzzle(Sudoku* sudoku) 
{   int i,j;
    for (i = 0; i < size; i++) 
        for (j = 0; j < size; j++) 
            if (sudoku->vertices[i][j]->value == 0) 
                return (i*size + j); 
    return -1; 
} 

int check(Sudoku* sudoku,int choice,int i,int j)
{   
    Cell* cell = sudoku->vertices[i][j];
    for(i=0;i<link_no;i++)
    {
        if (cell->links[i]->value == choice){
            return 0;
        }
    }   
    return 1;
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

