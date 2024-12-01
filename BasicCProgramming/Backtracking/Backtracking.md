# Notes on Backtracking:

1. Choice: What do you do?
    - Place a queen on a chess table.
    - Place a number on a sudoku board.
    - Add one more number to the binary sequence.
    - Add a bill to your deposit account.

2. Constraints: What are the restrictions?
    - The bus can only have k seats.
    - The binary sequence cannot be longer than n.
    - Queens cannot eliminate each other.
    - There must not be the same number in a row, column or 3x3 box on the Sudoku table.

3. Goal: When will we reach the end?
    - The length of the binary sequence, started from 0, has reached n.
    - The bus has taken n passengers, dropped all of them and returned.
    - There is no more gaps to place the queens.
    - The Sudoku has been filled.

Step 1: Express the decision space(table, sequence -> string, bus -> capacity variable, etc.)
Step 2: if(isValid) -> recursion.
Step 3: When you recurse, you will now think of the base case. Construct a good base case is needed. 
Step 4: Backtrack

If it works out: Sub-problem -> Decision Space -> Constraints -> Base case.
If it does not work out: Backtrack.