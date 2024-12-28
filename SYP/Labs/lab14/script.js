class Sudoku {
  constructor() {
    this.initialBoard = this.createEmptyBoard();
    this.board = this.cloneBoard(this.initialBoard);
  }

  createEmptyBoard() {
    const board = [];
    for (let i = 0; i < 9; i++) {
      const row = [];
      for (let j = 0; j < 9; j++) {
        row.push(0);
      }
      board.push(row);
    }
    return board;
  }

  cloneBoard(board) {
    return board.map(row => [...row]);
  }

  resetBoard() {
    this.board = this.cloneBoard(this.initialBoard);
    console.log("Игровое поле сброшено");
  }

  checkRow(rowIndex) {
    const row = this.board[rowIndex];
    const seen = new Set();
    for (let num of row) {
      if (num !== 0 && seen.has(num)) return false;
      seen.add(num);
    }
    return true;
  }

  checkColumn(colIndex) {
    const seen = new Set();
    for (let row = 0; row < 9; row++) {
      const num = this.board[row][colIndex];
      if (num !== 0 && seen.has(num)) return false;
      seen.add(num);
    }
    return true;
  }

  checkSquare(squareIndex) {
    const seen = new Set();
    const startRow = Math.floor(squareIndex / 3) * 3;
    const startCol = (squareIndex % 3) * 3;

    for (let row = startRow; row < startRow + 3; row++) {
      for (let col = startCol; col < startCol + 3; col++) {
        const num = this.board[row][col];
        if (num !== 0 && seen.has(num)) return false;
        seen.add(num);
      }
    }
    return true;
  }

  validateBoard() {
    let isValid = true;

    const invalidRows = new Set();
    const invalidCols = new Set();
    const invalidSquares = new Set();

    for (let i = 0; i < 9; i++) {
      if (!this.checkRow(i)) {
        invalidRows.add(i);
        isValid = false;
      }
      if (!this.checkColumn(i)) {
        invalidCols.add(i);
        isValid = false;
      }
      if (!this.checkSquare(i)) {
        invalidSquares.add(i);
        isValid = false;
      }
    }

    this.highlightInvalidErrors(invalidRows, invalidCols, invalidSquares);
    if (isValid) this.highlightSuccess();

    return isValid;
  }

  highlightInvalidErrors(invalidRows, invalidCols, invalidSquares) {
    const cells = document.querySelectorAll(".cell");
    cells.forEach(cell => {
      const row = parseInt(cell.dataset.row, 10);
      const col = parseInt(cell.dataset.col, 10);

      const squareIndex = Math.floor(row / 3) * 3 + Math.floor(col / 3);

      if (invalidRows.has(row) || invalidCols.has(col) || invalidSquares.has(squareIndex)) {
        cell.classList.add("error");
      } else {
        cell.classList.remove("error");
      }
    });
  }

  highlightSuccess() {
    const cells = document.querySelectorAll(".cell");
    cells.forEach(cell => {
      cell.classList.add("success");
    });
  }

  // Генерация решенного поля
  generateBoard() {
    const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9];

    const fillBoard = (row, col) => {
      if (row === 9) return true;
      if (col === 9) return fillBoard(row + 1, 0);

      for (let num of this.shuffleArray(numbers)) {
        if (this.isSafe(row, col, num)) {
          this.board[row][col] = num;
          if (fillBoard(row, col + 1)) return true;
          this.board[row][col] = 0;
        }
      }
      return false;
    };

    this.resetBoard();
    fillBoard(0, 0);
    console.log("Игровое поле сгенерировано");
  }

  createPuzzle(freeCells = 60) {
    const puzzle = this.cloneBoard(this.board);
    let cellsCleared = 0;

    while (cellsCleared < freeCells) {
      const row = Math.floor(Math.random() * 9);
      const col = Math.floor(Math.random() * 9);

      if (puzzle[row][col] !== 0) {
        puzzle[row][col] = 0;
        cellsCleared++;
      }
    }

    return puzzle;
  }

  isSafe(row, col, num) {
    for (let i = 0; i < 9; i++) {
      if (
        this.board[row][i] === num ||
        this.board[i][col] === num ||
        this.board[
          Math.floor(row / 3) * 3 + Math.floor(i / 3)
        ][Math.floor(col / 3) * 3 + (i % 3)] === num
      ) {
        return false;
      }
    }
    return true;
  }

  shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
  }
}

document.addEventListener("DOMContentLoaded", () => {
  const game = new Sudoku();
  
  

  const boardElement = document.getElementById("sudoku-board");
  const generateBoardButton = document.getElementById("generate-board");
  const validateBoardButton = document.getElementById("validate-board");
  const generateSolvedBoardButton = document.getElementById("generate-solved-board");

  function renderBoard(board) {
    boardElement.innerHTML = "";

    for (let row = 0; row < 9; row++) {
      for (let col = 0; col < 9; col++) {
        const cell = document.createElement("input");
        cell.type = "text";
        cell.className = "cell";
        cell.maxLength = 1;
        const value = board[row][col];
        cell.value = value === 0 ? "" : value;
        cell.dataset.row = row;
        cell.dataset.col = col;


        if (value !== 0) {
          cell.disabled = true;
          cell.classList.add("disabled");
        }

        cell.addEventListener("input", (e) => {
          const val = parseInt(e.target.value, 10);
          if (!isNaN(val) && val >= 1 && val <= 9) {
            game.board[row][col] = val;
          } else {
            e.target.value = "";
            game.board[row][col] = 0;
          }
        });

        boardElement.appendChild(cell);
      }
    }
  }


  generateBoardButton.addEventListener("click", () => {
    game.resetBoard();
    game.generateBoard();
    const puzzle = game.createPuzzle();
    renderBoard(puzzle);
  });


  validateBoardButton.addEventListener("click", () => {
    const isValid = game.validateBoard();
    alert(isValid ? "Поле корректно!" : "Есть ошибки в поле.");
  });

  generateSolvedBoardButton.addEventListener("click", () => {
    game.generateBoard();
    renderBoard(game.board);
  });

  renderBoard(game.board);
});

const obj = { 
    name :"wii",
    age:21
}

let {name, age} = obj;
console.log(age+" "+name);