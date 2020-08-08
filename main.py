from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from starlette.middleware.cors import CORSMiddleware
from starlette.requests import Request
import c_utils
from typing import List
app = FastAPI()

app.add_middleware(CORSMiddleware,allow_origins=['*'],allow_credentials=True,allow_methods=['*'],allow_headers = ["*"] )
#app.mount("/",StaticFiles( directory = "frontend/public" ),name = "static")

@app.get("/api/test")
def home():
    return { "data" : "hello" }

@app.get("/api/generate")
def generate_sudoku():
    grid = c_utils.generate_grid()
    return { "data" : str(grid) }


@app.get("/api/solution/")
async def solve_sudoku(grid: str = "hi"):
    solved_grid = c_utils.solve_grid(eval(grid))
    #print("SOLVED GRID",solved_grid)
    return { "data": str(solved_grid) }
