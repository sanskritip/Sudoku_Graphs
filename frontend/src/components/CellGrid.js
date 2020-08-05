import React,{useState} from 'react';
import Cell from './Cell'

function CellGrid (){
        var {active,setActive} = useState(false)
        return ( 
            <div className="cell-grid">
                <div className="row">
                    <Cell />
                    <Cell />
                    <Cell />
                </div>
                <div className="row">
                    <Cell />
                    <Cell />
                    <Cell />
                </div>
                <div className="row">
                    <Cell />
                    <Cell />
                    <Cell />
                </div>
            </div>
        );
}

export default CellGrid