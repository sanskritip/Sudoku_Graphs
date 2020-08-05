import React from 'react';
import Navbar from './components/Navbar'
import Board from './components/Board'
import Button from './components/Button'

function App() {
  return (
    <div className="App">
      <Navbar/>
      <div className="board-container">
        <Board />
        
      </div>
      <div className="button-container">
        <Button text = "Generate puzzle" />
        <Button text = "Scan puzzle" />
        <Button text = "Solve puzzle" />
      </div>
    </div>
  );
}

export default App;
