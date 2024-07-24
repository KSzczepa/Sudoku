# Sudoku
 
This project is a simple console game. 
User can choose difficulty level and start the game. 
Any time it is possible to see solved sudoku problem. It was implemented using backtracking algorithm. 

The backtracking algorithm is one of the most popular methods of solving Sudoku. It involves trially placing digits in empty spaces and going back (backtracking) when a conflict is encountered.

Advantages of the Backtracking Algorithm
* Simplicity - The algorithm is relatively simple to understand and implement. It intuitively and directly follows the rules of Sudoku.
* Guaranteed to Find a Solution - If Sudoku has a solution, the algorithm will find it.
* Flexibility - It can be adapted to solve other combinatorial problems beyond Sudoku.
  
Disadvantages of the Backtracking Algorithm
* Computational complexity - The algorithm has high time complexity in the worst case. May require checking all possible combinations (9^81 for a full Sudoku board). In practice, for large and complex puzzles, it can be very slow.
* Lack of Efficiency for Hard Problems - The algorithm may be ineffective in the case of difficult puzzles with a small number of filled cells, where the number of necessary operations increases significantly.
* No Heuristics - The basic backtracking algorithm does not use any advanced heuristics that could significantly speed up the solving process.
