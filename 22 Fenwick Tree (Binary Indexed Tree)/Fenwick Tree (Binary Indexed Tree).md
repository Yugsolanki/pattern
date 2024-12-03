# Fenwick Tree (Binary Indexed Tree)

## 1. Concise Explanation

A Fenwick Tree, also known as a Binary Indexed Tree (BIT), is a data structure that efficiently supports dynamic range queries and updates on an array. It provides a balance between the simplicity of an array and the power of a segment tree, allowing for logarithmic time complexity for both point updates and range sum queries.

## 2. Detailed Walkthrough

The key idea behind a Fenwick Tree is to represent an array of n elements as a virtual binary tree, where each node stores the sum of a range of elements.

### Operations:

1. **Initialization**: 
   - Create an array of size n+1 (1-indexed for simplicity)
   - Each index i in the tree is responsible for the sum of elements from i - (i & -i) + 1 to i in the original array

2. **Update Operation**:
   - To update an element at index i, we need to update all the ranges that include this index
   - We start from index i and move up the tree by adding the least significant bit (LSB)
   - The LSB is calculated using the bitwise operation: i & (-i)

3. **Query Operation (Prefix Sum)**:
   - To get the sum of elements from index 1 to i, we accumulate values as we move up the tree
   - We start from index i and move up by removing the LSB

### Step-by-step Example:

Let's consider an array: [3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3]

1. **Initialization**:
   - Create a Fenwick tree array of size 12 (11 + 1 for 1-indexing)
   - Fill it based on the original array

2. **Update Operation** (e.g., increment index 5 by 2):
   - Start at index 5
   - Update indices: 5, 6, 8, 16 (if within array bounds)
   
3. **Query Operation** (e.g., sum of first 7 elements):
   - Start at index 7
   - Sum indices: 7, 6, 4

## 3. Code Implementation

Here's a Python implementation of a Fenwick Tree:

```python
class FenwickTree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta):
        while i <= self.size:
            self.tree[i] += delta
            i += i & (-i)
    
    def query(self, i):
        total = 0
        while i > 0:
            total += self.tree[i]
            i -= i & (-i)
        return total

    def range_query(self, left, right):
        return self.query(right) - self.query(left - 1)

# Example usage
arr = [3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3]
n = len(arr)

# Initialize Fenwick Tree
fenwick = FenwickTree(n)
for i in range(1, n + 1):
    fenwick.update(i, arr[i - 1])

# Query sum of first 7 elements
print(fenwick.query(7))  # Output: 16

# Update: increment 5th element by 2
fenwick.update(5, 2)

# Query sum of elements from index 3 to 8
print(fenwick.range_query(3, 8))  # Output: 17
```

## 4. Applications

Fenwick Trees are particularly useful for:

1. Range sum queries with updates
2. Counting inversions in an array
3. Finding cumulative frequency
4. Implementing arithmetic coding

They are most effective in scenarios where:
- You need to perform both range queries and point updates
- The underlying data is one-dimensional
- You want a simpler implementation compared to segment trees

## 5. Practice Problems

### Easy:
1. Find the sum of the first k elements in an array
2. Update a single element in the array
3. Count the number of elements less than or equal to k in a range
4. Find the element at a given rank in a range
5. Implement a dynamic cumulative frequency table

### Medium:
1. Count inversions in an array
2. Range update and point query
3. 2D Fenwick Tree for rectangle sum queries
4. Find the k-th smallest element in a range
5. Implement a binary search on a Fenwick Tree

### Hard:
1. Implement persistent Fenwick Tree
2. Range update and range query with lazy propagation
3. Solve dynamic connectivity problem using Fenwick Tree
4. Implement a Fenwick Tree for range minimum query
5. Use Fenwick Tree for solving dynamic longest increasing subsequence problem
