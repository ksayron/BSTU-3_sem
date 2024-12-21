function getRandomInt(upper) { return Math.floor( Math.random() * upper ); }


class Sudoku {
  constructor() {
      this.refillMatrix();
  }

  
  refillMatrix() {
      this.matrix = Array.from({ length: 9 }, () => Array(9).fill(0));
  }

  
  #checkRow(row) {
      const seen = new Set();
      for (let col = 0; col < 9; col++) {
          const value = this.matrix[row][col];
          if (value !== 0) {
              if (seen.has(value)) return row + 1;
              seen.add(value);
          }
      }
      return null;
  }

  #checkColumn(col) {
      const seen = new Set();
      for (let row = 0; row < 9; row++) {
          const value = this.matrix[row][col];
          if (value !== 0) {
              if (seen.has(value)) return col + 1; 
              seen.add(value);
          }
      }
      return null;
  }

  #checkSquare(rowStart, colStart) {
      const seen = new Set();
      for (let row = rowStart; row < rowStart + 3; row++) {
          for (let col = colStart; col < colStart + 3; col++) {
              const value = this.matrix[row][col];
              if (value !== 0) {
                  if (seen.has(value)) return [rowStart / 3 + 1, colStart / 3 + 1];
                  seen.add(value);
              }
          }
      }
      return null;
  }

  checkErrors() {
      let errors = { rows: [], columns: [], squares: [] };

      for (let i = 0; i < 9; i++) {
          const rowError = this.#checkRow(i);
          if (rowError) errors.rows.push(rowError);

          const colError = this.#checkColumn(i);
          if (colError) errors.columns.push(colError);
      }

      for (let row = 0; row < 9; row += 3) {
          for (let col = 0; col < 9; col += 3) {
              const squareError = this.#checkSquare(row, col);
              if (squareError) errors.squares.push(`(${squareError[0]}, ${squareError[1]})`);
          }
      }

      console.log("Проверка:");
      if (!errors.rows.length && !errors.columns.length && !errors.squares.length)
          return true;
      else return false;
  }


  initializeSudoku() {
    this.matrix.forEach((row, i) => {
      row.forEach((_, j) => {
        if (getRandomInt(100) < 50) {
          let newValue = getRandomInt(8) + 1;
          console.log(newValue);
          if(this.#isValidMove(i,j,newValue)){
            this.matrix[i][j] = newValue;
          console.log(this.matrix[i][j]);}
        }
      });
    });
  }
  
  generateMatrix() {
      this.refillMatrix();
      this.initializeSudoku();
  }

  // Проверка возможности установить число в ячейку
  #isValidMove(row, col, num) {
      for (let i = 0; i < 9; i++) {
          if (this.matrix[row][i] === num || this.matrix[i][col] === num) return false;
      }

      const rowStart = Math.floor(row / 3) * 3;
      const colStart = Math.floor(col / 3) * 3;
      for (let r = rowStart; r < rowStart + 3; r++) {
          for (let c = colStart; c < colStart + 3; c++) {
              if (this.matrix[r][c] === num) return false;
          }
      }
      return true;
  }

  
}

let sudoku = new Sudoku();
sudoku.generateMatrix();
console.log(sudoku.matrix);


document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('Restart').addEventListener('click',
      function addByClick() {
        sudoku.generateMatrix();
      }
    );
  });
