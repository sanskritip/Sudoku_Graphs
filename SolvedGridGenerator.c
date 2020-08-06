#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//int grid[9][9];
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
    int i, j; 
    for (i = 0; i < 9; i++) 
    {
      for (j = 0; j < 9; j++) 
        printf("%d ", arr[i][j]); 
      printf("\n");
    }
      
} 
int prow,pcol;
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
                printf("value %d \n",value);
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
                            print(grid);
                            prow=row;pcol=col;
                            flag=1;
                            printf("__________________\n");
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

int generator_main()
{
    int grid[9][9] = {0};
    //print(grid);
    bool temp=fillgrid(grid);
    //printf("Complete :\n");
    print(grid);
    
}
