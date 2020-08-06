import React from 'react';
import gameContext from '../context'

class Cell extends React.Component {
    static contextType = gameContext
    
    handleChange = (e) => {
        var {editGrid,setGrid} = this.context
        var {row,col} = this.props
        var value = parseInt(e.target.value)
        if(value)
        {
            
            editGrid[col][row] = value
            setGrid(editGrid)
        }
    }
    
    render(){
        var {row,col} = this.props
        var numberx = (this.context.grid[col][row]).toString()
        var disabled = (numberx === "0")? false: true
        var number = (this.context.editGrid[col][row]).toString()
        if(number == "0"){
            number = ""
        }
        return ( 
            <div className="cell">
                <input 
                    disabled = {disabled}
                    type="text"
                    maxLength="1" 
                    id = "cell-input"
                    className="cell-input"  
                    value = {number}
                    onChange = {this.handleChange}
                    onKeyDown = {
                        (e) => {
                            if(e.key === "Backspace" || e.key === "Delete"){
                                const {editGrid,setGrid} = this.context
                                editGrid[col][row] = 0
                                setGrid(editGrid)
                            }
                        }
                    }
                />
            </div>
        );
    }
}

export default Cell