from fastapi import FastAPI
from fastapi.staticfiles import StaticFiles
from starlette.middleware.cors import CORSMiddleware
import c_utils

app = FastAPI()

app.add_middleware(CORSMiddleware,allow_origins=['*'])
#app.mount("/",StaticFiles( directory = "frontend/public" ),name = "static")

@app.get("/api/test")
def home():
    return { "data" : "hello" }

@app.get("/api/generate")
def generate_sudoku():
    grid = c_utils.generate_grid()
    return { "data" : str(grid) }


