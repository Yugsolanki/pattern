# Matrix Traversal Pattern

## 1. Concise Explanation and Purpose

The matrix traversal pattern is a technique used to explore and process the elements of a two-dimensional matrix or grid data structure. It involves visiting each element in the matrix in a specific order, typically row-by-row or column-by-column.

The purpose of the matrix traversal pattern is to provide a systematic way to access and manipulate the data stored in a matrix, enabling various operations such as:

- Searching for a specific value or element in the matrix
- Performing transformations or modifications on the matrix
- Calculating statistics or aggregations over the matrix elements
- Solving problems that can be modeled as a two-dimensional grid or matrix

## 2. Detailed Walkthrough

The matrix traversal pattern can be implemented using different approaches, such as row-major order, column-major order, or spiral order. Let's go through the step-by-step implementation of each approach:

### Row-Major Order Traversal

1. **Initialize the traversal**: Set the row and column indices to 0, representing the top-left corner of the matrix.
2. **Traverse the rows**: For each row, visit the elements from the leftmost column to the rightmost column.
3. **Move to the next row**: After completing the traversal of a row, increment the row index to move to the next row.
4. **Repeat**: Continue the row-by-row traversal until all the rows have been visited.

### Column-Major Order Traversal

1. **Initialize the traversal**: Set the row and column indices to 0, representing the top-left corner of the matrix.
2. **Traverse the columns**: For each column, visit the elements from the topmost row to the bottommost row.
3. **Move to the next column**: After completing the traversal of a column, increment the column index to move to the next column.
4. **Repeat**: Continue the column-by-column traversal until all the columns have been visited.

### Spiral Order Traversal

1. **Initialize the traversal**: Set the row and column indices to 0, representing the top-left corner of the matrix.
2. **Define the boundaries**: Maintain four variables to keep track of the current boundaries of the spiral: `top`, `bottom`, `left`, and `right`.
3. **Traverse the spiral**: Perform the following steps until all the elements have been visited:
   - Move right from the top-left corner to the top-right corner.
   - Move down from the top-right corner to the bottom-right corner.
   - Move left from the bottom-right corner to the bottom-left corner.
   - Move up from the bottom-left corner to the top-left corner.
4. **Update the boundaries**: After each step, update the boundaries to exclude the elements that have already been visited.
5. **Repeat**: Continue the spiral traversal until all the elements have been visited.

Here's an example of a matrix and the corresponding traversal orders:

```
Matrix:
[1, 2, 3, 4]
[5, 6, 7, 8]
[9, 10, 11, 12]
[13, 14, 15, 16]

Row-Major Order: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Column-Major Order: [1, 5, 9, 13, 14, 15, 16, 12, 8, 4, 3, 7, 11, 10, 6, 2]
Spiral Order: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
```

## 3. Code Implementation

Here's an implementation of the matrix traversal pattern in Python:

```python
def row_major_traversal(matrix):
    result = []
    for row in matrix:
        result.extend(row)
    return result

def column_major_traversal(matrix):
    result = []
    for j in range(len(matrix[0])):
        for i in range(len(matrix)):
            result.append(matrix[i][j])
    return result

def spiral_traversal(matrix):
    if not matrix:
        return []

    result = []
    top, bottom, left, right = 0, len(matrix) - 1, 0, len(matrix[0]) - 1

    while top <= bottom and left <= right:
        # Traverse right
        for j in range(left, right + 1):
            result.append(matrix[top][j])
        top += 1

        # Traverse down
        for i in range(top, bottom + 1):
            result.append(matrix[i][right])
        right -= 1

        # Traverse left
        if top <= bottom:
            for j in range(right, left - 1, -1):
                result.append(matrix[bottom][j])
            bottom -= 1

        # Traverse up
        if left <= right:
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1

    return result
```

In this implementation, the `row_major_traversal` and `column_major_traversal` functions use nested loops to visit the elements in the respective order. The `spiral_traversal` function uses four variables to keep track of the current boundaries of the spiral and performs a series of movements to visit the elements in a spiral pattern.

## 4. Applications and Scenarios

**Applications:**
- Searching for a specific value or element in a matrix.
- Performing image processing or transformation operations on a 2D image represented as a matrix.
- Solving problems that involve working with grid-based data, such as mazes, maps, or game boards.
- Implementing matrix-based algorithms, like Dijkstra's algorithm for finding the shortest path in a weighted graph.

**Scenarios:**
- Navigating through a spreadsheet or a two-dimensional data table.
- Traversing a maze or a grid-based game environment.
- Processing satellite or aerial imagery represented as a 2D array of pixels.
- Analyzing data stored in a two-dimensional format, such as a seismic dataset or a weather grid.

## 5. Practice Problems

### Easy
1. [LeetCode 48. Rotate Image](https://leetcode.com/problems/rotate-image/)
2. [LeetCode 73. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
3. [LeetCode 566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/)
4. [LeetCode 1582. Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)
5. [LeetCode 1260. Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)

### Medium
1. [LeetCode 54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
2. [LeetCode 59. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)
3. [LeetCode 329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
4. [LeetCode 463. Island Perimeter](https://leetcode.com/problems/island-perimeter/)
5. [LeetCode 885. Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/)

### Difficult
1. [LeetCode 317. Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/)
2. [LeetCode 410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)
3. [LeetCode 675. Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)
4. [LeetCode 741. Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)
5. [LeetCode 862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)