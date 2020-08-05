import React from 'react';


class Cell extends React.Component {
    state = {
        number:""
    }
    handleChange = (e) => {
        var value = parseInt(e.target.value)
        if(value)
        {
            this.setState({
                number:e.target.value
            })
        }
    }
    render(){
        var {number} = this.state
        return ( 
            <div className="cell">
                <input 
                    type="text"
                    maxLength="1" 
                    id = "cell-input"
                    className="cell-input"  
                    value = {number}
                    onChange = {this.handleChange}
                    onKeyDown = {
                        (e) => {
                            if(e.key === "Backspace" || e.key === "Delete"){
                                this.setState({
                                    number:''
                                })
                            }
                        }
                    }
                />
            </div>
        );
    }
}

export default Cell