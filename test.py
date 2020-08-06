from ctypes import *

so_file = r'/home/avinashvk/Desktop/Sudoku_Graphs/solver.so'
sudoku = CDLL(so_file)

grid = ((c_int * 9)* 9)()

sudoku.generator(grid)

unsolved = [[ grid[i][j] for j in range(9)] for i in range(9)]

#sudoku.print(grid)
sudoku.solver(grid)

#sudoku.print(grid)
solved = [[ grid[i][j] for j in range(9) ] for i in range(9)]

print("unsolved array:",unsolved)
print("Solved array:",solved)


