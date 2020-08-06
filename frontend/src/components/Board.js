import React,{useState} from 'react';
import CellGrid from './CellGrid'

function Board (){
        var {active,setActive} = useState(false)
        return ( 
            <div className="board">
                <div className="row">
                    <CellGrid col={0} row={0} />
                    <CellGrid col={0} row={1} />
                    <CellGrid col={0} row={2} />
                </div>
                <div className="row">
                    <CellGrid col={1} row={0} />
                    <CellGrid col={1} row={1} />
                    <CellGrid col={1} row={2} />
                </div>
                <div className="row">
                    <CellGrid col={2} row={0} />
                    <CellGrid col={2} row={1} />
                    <CellGrid col={2} row={2} />
                </div>
            </div>
        );
}

export default Board