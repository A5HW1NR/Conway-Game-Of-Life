# Conway Game Of Life
My implementation of the Conway Game of Life problem. 
The input to the program is a square binay matrix. 
A live cell --> 1 and a dead cell is --> 0

The next generation is dictated by the rules:
          1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
          2. Any live cell with two or three live neighbors lives on to the next generation.
          3. Any live cell with moe than three live neighbors dies, as if by over-population.
          4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
          5. Treat out of bounds neighbors as dead.
