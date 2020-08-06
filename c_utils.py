from ctypes import *

so_file = r'/home/avinashvk/Desktop/Sudoku_Graphs/solver.so'
sudoku_functions = CDLL(so_file)

def generate_grid():
    grid = ((c_int * 9)* 9)()
    sudoku_functions.generator(grid)
    unsolved = [[ grid[i][j] for j in range(9)] for i in range(9)]
    return unsolved

def solve_grid(python_grid):
    grid = ((c_int * 9)* 9)()
    for i in range(9):
        for j in range(9):
            grid[i][j] = python_grid[i][j]
    sudoku_functions.solver(grid)
    solved = [[ grid[i][j] for j in range(9)] for i in range(9)]
    return solved