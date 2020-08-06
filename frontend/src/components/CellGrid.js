import React,{useState} from 'react';
import Cell from './Cell'

function CellGrid ({row,col}){
        var {active,setActive} = useState(false)
        var rowdif = row*3
        var coldif = col*3
        return ( 
            <div className="cell-grid">
                <div className="row">
                    <Cell col={0+coldif} row={0+rowdif} />    
                    <Cell col={0+coldif} row={1+rowdif} />
                    <Cell col={0+coldif} row={2+rowdif} />
                </div>
                <div className="row">
                    <Cell col={1+coldif} row={0+rowdif} />
                    <Cell col={1+coldif} row={1+rowdif} />
                    <Cell col={1+coldif} row={2+rowdif} />
                </div>
                <div className="row">
                    <Cell col={2+coldif} row={0+rowdif} />
                    <Cell col={2+coldif} row={1+rowdif} />
                    <Cell col={2+coldif} row={2+rowdif} />
                </div>
            </div>
        );
}

export default CellGrid