import React from 'react';
import Navbar from './components/Navbar'
import Board from './components/Board'
import Button from './components/Button'
import API from './api/api'
import gameContext from './context'

class App extends React.Component {
  
  state = {
    grid:[...Array(9)].map(x => Array(9).fill(0)),
    editGrid:[...Array(9)].map(x => Array(9).fill(0)),
    
  }
  setGrid = (editGrid) => {
    this.setState({
      editGrid:editGrid
    })
  }
  
  handleGenerate = async () =>{
    var resp = await API.generate_puzzle()
   
      this.setState({
        grid:[...resp],
        editGrid:JSON.parse(JSON.stringify(resp)),
      });
  }
  
  render(){
    return (
      <div className="App">
        <gameContext.Provider 
          value = {{
            grid : this.state.grid,
            editGrid: this.state.editGrid,
            setGrid : this.setGrid
          }}
        >
          <Navbar/>
          <div className="board-container">
            <Board />
          </div>
          <div className="button-container">
            <Button text = "Generate puzzle" onClick = {this.handleGenerate} />
            <Button text = "Scan puzzle" />
            <Button text = "Solve puzzle" />
          </div>
        </gameContext.Provider>
      </div>
    );
  }
}

export default App;
