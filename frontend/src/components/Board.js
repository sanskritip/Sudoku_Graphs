import React,{useState} from 'react';
import CellGrid from './CellGrid'

function Board (){
        var {active,setActive} = useState(false)
        return ( 
            <div className="board">
                <div className="row">
                    <CellGrid />
                    <CellGrid />
                    <CellGrid />
                </div>
                <div className="row">
                    <CellGrid />
                    <CellGrid />
                    <CellGrid />
                </div>
                <div className="row">
                    <CellGrid />
                    <CellGrid />
                    <CellGrid />
                </div>
            </div>
        );
}

export default Board