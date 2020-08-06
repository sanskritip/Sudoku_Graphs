#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define size 9
#define puzzle "./q3.txt"
#define link_no 20
int counter;
typedef struct Cell
{
    int value;
    struct Cell** links;
}Cell;
typedef struct Sudoku
{
    Cell* vertices[size][size];

}Sudoku;
//Prototypes
Cell* create_cell();
void add_edge(Cell* source,Cell* target);
Sudoku* initialize_board();
int isSolvedPuzzle(Sudoku* sudoku);
int check(Sudoku* sudoku,int choice,int i,int j);
void recurse_Sudoku(Sudoku* sudoku);
void generator_solve_Sudoku(int grid[9][9]);
void display_board(Sudoku* sudoku);
int solve_Sudoku(Sudoku* sudoku);
//Function Definition
Cell* create_cell()
{
    Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->value = 0;
    cell->links = (Cell**)malloc(sizeof(Cell*)*link_no);
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
Sudoku* initialize_board()
{
    Sudoku* sudoku  = (Sudoku *)malloc(sizeof(Sudoku));
    int i,j,k;
    for (i=0;i<size;i++)
    {
        for(j =0;j<size;j++)
            sudoku->vertices[i][j] = create_cell();
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

void generator_solve_Sudoku(int arr[9][9])
{   //printf("In generator solver \n");
    Sudoku* sudoku = initialize_board(); 
    int d,i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            sudoku->vertices[i][j]->value = arr[i][j];
        }
    }
    counter = 0;
    recurse_Sudoku(sudoku);
    free(sudoku);
}
void display_board(Sudoku* sudoku)
{	printf("\n_________________________\n");
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

//everything required to generate a new puzzle 

int numlist[]={1,2,3,4,5,6,7,8,9};
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}
int randomi(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
bool UsedInBox( int grid[9][9], int boxStartRow,int boxStartCol, int num) 
{   int row,col;
    for (row = 0; row < 3; row++) 
        for (col = 0; col < 3; col++) 
            if ( grid[row + boxStartRow][col + boxStartCol] == num) 
                return true; 
    return false; 
} 
bool checkgrid(int grid[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(grid[i][j]==0)
                return false;
    return true;

}
void print(int arr[9][9]) 
{ 
    printf("\n_________________________\n");
    int space = pow(size,0.5);
    int i,j;
    for(i=0;i<size;i++)
    {   printf("|");
    	for(j = 0;j<size;j++)
        {
            printf("%d ",arr[i][j]);
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
bool fillgrid(int grid[9][9])
{
    int i,j,k,row,col,flag;
    //Finding next empty cell(filled with 0)
    for(i=0;i<81;i++)
    {   flag=0;
        row=floor(i/9);
        col=i%9;
        if(grid[row][col]==0)
        {
            randomize(numlist,9);
            for(j=0;j<9;j++)
            {
                int value=numlist[j];
                //printf("value %d \n",value);
                int flag_rowcheck=1;
                //Checking if value isn't already used in current row
                for(k=0;k<9;k++)
                    if(grid[row][k]==value)
                        flag_rowcheck=0;
                //If value not already in current row
                if(flag_rowcheck)
                {
                    int flag_colcheck=1;
                    //Checking if value isn't already used in current row
                    for(k=0;k<9;k++)
                        if(grid[k][col]==value)
                            flag_colcheck=0;
                    //If value not already in current column
                    if(flag_colcheck)
                    {   //Checking if value isn't already used in current square
                        bool flag_squarecheck;
                        if(row<3)
                            if(col<3)
                                flag_squarecheck=UsedInBox(grid,0,0,value);
                            else if(col<6)
                                flag_squarecheck=UsedInBox(grid,0,3,value);
                            else
                                flag_squarecheck=UsedInBox(grid,0,6,value);
                        else if(row<6)
                            if(col<3)
                                flag_squarecheck=UsedInBox(grid,3,0,value);
                            else if(col<6)
                                flag_squarecheck=UsedInBox(grid,3,3,value);
                            else
                                flag_squarecheck=UsedInBox(grid,3,6,value);
                        else
                            if(col<3)
                                flag_squarecheck=UsedInBox(grid,6,0,value);
                            else if(col<6)
                                flag_squarecheck=UsedInBox(grid,6,3,value);
                            else
                                flag_squarecheck=UsedInBox(grid,6,6,value);
                        //If value not used in current square
                        if(!flag_squarecheck)
                        {
                            grid[row][col]=value;
                            //print(grid);
                            flag=1;
                            //printf("__________________\n");
                            if(checkgrid(grid))
                                return true;
                            else{
                                if(fillgrid(grid))
                                    return true;
                            }
                        }
                    }
                }
            }
            //If none of the numbers can safely be filled in the current cell
            break;
        }
    } 
    grid[row][col]=0;
    return false;
}

void generator_main(int grid[9][9])
{
    bool temp=fillgrid(grid);
    printf("Completed puzzle \n");
    print(grid);
    int attempts=40;
    while(attempts>0)
    {   //printf("Starting attempt %d \n",attempts); 
        int row=randomi(0,8);
        int col=randomi(0,8);
        while(grid[row][col]==0)
        {
            row=randomi(0,8);
            col=randomi(0,8);
        }
        int backup=grid[row][col];
        grid[row][col]=0;
        generator_solve_Sudoku(grid);
        //printf("%d Counter value \n",counter);
        if(counter!=1)
            grid[row][col]=backup;
        else
            attempts--;
            //printf("Puzzle state after attempt %d \n",5-attempts);
            //print(grid);
    }    
}
