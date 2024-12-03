# Backtracking Pattern

## 1. Concise Explanation and Purpose

The backtracking pattern is a general algorithmic technique that considers searching every possible combination in order to solve a computational problem. It incrementally builds candidates to the solutions and checks if each candidate satisfies the problem's statement. If not, it backtracks to the previous step and tries a different candidate.

The purpose of the backtracking pattern is to provide a systematic way to explore all possible solutions to a problem, particularly when the solution is not immediately apparent or when the problem involves making a series of choices. It is often used to solve problems that can be expressed as finding a set of solutions that satisfy a set of constraints.

## 2. Detailed Walkthrough

The backtracking pattern typically involves the following steps:

1. **Define the problem**: Clearly define the problem you are trying to solve, including the input, the desired output, and the constraints.
2. **Identify the candidate solutions**: Determine the set of possible candidate solutions that you need to explore.
3. **Build the solution incrementally**: Start with an empty solution and gradually add elements to it, checking at each step whether the partial solution satisfies the problem's constraints.
4. **Backtrack when a solution is not viable**: If the current partial solution cannot be completed to a full solution, backtrack to the previous step and try a different candidate.
5. **Record the solution**: When a complete solution is found, add it to the set of valid solutions.
6. **Repeat**: Continue the process of building, checking, and backtracking until all possible solutions have been explored.

Here's a step-by-step walkthrough of the backtracking pattern for solving the classic N-Queens problem:

```
Problem: Place N queens on an N x N chessboard such that no two queens attack each other.

1. Define the problem:
   - Input: The number of queens N
   - Output: A list of positions (row, column) where the queens are placed

2. Identify the candidate solutions:
   - The candidate solutions are all possible placements of the N queens on the chessboard.

3. Build the solution incrementally:
   - Start with an empty solution (no queens placed).
   - Place the first queen in the first row, at the leftmost column.
   - Place the second queen in the second row, at the leftmost column that is safe (not attacked by the first queen).
   - Repeat this process for the remaining queens, placing each queen in the leftmost safe column of the current row.

4. Backtrack when a solution is not viable:
   - If a queen cannot be placed in any column of the current row, backtrack to the previous row and try a different column for the queen in that row.

5. Record the solution:
   - When all N queens have been placed successfully, record the current board configuration as a valid solution.

6. Repeat:
   - Continue the process of building, checking, and backtracking until all possible solutions have been explored.
```

The intermediate steps and results would depend on the specific implementation and the size of the chessboard (N).

## 3. Code Implementation

Here's an implementation of the backtracking pattern in Python to solve the N-Queens problem:

```python
def solve_n_queens(n):
    def is_safe(board, row, col):
        # Check this row on the left side
        for i in range(col):
            if board[row][i] == 1:
                return False

        # Check upper diagonal on the left side
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1

        # Check lower diagonal on the left side
        i, j = row, col
        while i < n and j >= 0:
            if board[i][j] == 1:
                return False
            i += 1
            j -= 1

        return True

    def solve_queens(board, col):
        # Base case: If all queens are placed, return True
        if col == n:
            solutions.append([''.join(['Q' if board[i][j] else '.' for j in range(n)]) for i in range(n)])
            return True

        # Place this queen in all rows one by one
        for i in range(n):
            if is_safe(board, i, col):
                board[i][col] = 1

                # Recur to place rest of the queens
                solve_queens(board, col + 1)

                # If placing a queen in the board[i][col] doesn't lead to a solution, remove the queen
                board[i][col] = 0

    solutions = []
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve_queens(board, 0)
    return solutions
```

In this implementation, the `is_safe` function checks whether it is safe to place a queen in a given position on the board, considering the existing queens. The `solve_queens` function recursively places the queens on the board, backtracking when a solution is not viable. The `solve_n_queens` function initializes the board and calls the `solve_queens` function to find all the valid solutions.

## 4. Applications and Scenarios

**Applications:**
- Solving constraint satisfaction problems, such as the N-Queens problem, the Sudoku puzzle, or the graph coloring problem.
- Finding all possible solutions to a problem, rather than just a single solution.
- Solving optimization problems, where the goal is to find the best solution among all possible solutions.
- Implementing algorithms that require exploring a large search space, such as game-playing algorithms (e.g., chess, Go) or planning algorithms (e.g., robot motion planning).

**Scenarios:**
- Scheduling problems, where you need to assign tasks to resources while respecting various constraints.
- Combinatorial optimization problems, such as the Traveling Salesman problem or the Knapsack problem.
- Puzzle-solving applications, where you need to find a sequence of moves that satisfies certain conditions.
- Configuration problems, where you need to select the best combination of options from a set of choices.

## 5. Practice Problems

### Easy
1. [LeetCode 17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
2. [LeetCode 39. Combination Sum](https://leetcode.com/problems/combination-sum/)
3. [LeetCode 46. Permutations](https://leetcode.com/problems/permutations/)
4. [LeetCode 78. Subsets](https://leetcode.com/problems/subsets/)
5. [LeetCode 784. Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)

### Medium
1. [LeetCode 37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
2. [LeetCode 51. N-Queens](https://leetcode.com/problems/n-queens/)
3. [LeetCode 77. Combinations](https://leetcode.com/problems/combinations/)
4. [LeetCode 90. Subsets II](https://leetcode.com/problems/subsets-ii/)
5. [LeetCode 140. Word Break II](https://leetcode.com/problems/word-break-ii/)

### Difficult
1. [LeetCode 212. Word Search II](https://leetcode.com/problems/word-search-ii/)
2. [LeetCode 425. Word Squares](https://leetcode.com/problems/word-squares/)
3. [LeetCode 472. Concatenated Words](https://leetcode.com/problems/concatenated-words/)
4. [LeetCode 691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/)
5. [LeetCode 980. Unique Paths III](https://leetcode.com/problems/unique-paths-iii/)