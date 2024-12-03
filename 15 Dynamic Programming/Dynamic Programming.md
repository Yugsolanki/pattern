# Dynamic Programming

## 1. Explanation of the Pattern and Its Purpose

Dynamic Programming (DP) is an algorithmic technique for solving complex problems by breaking them down into smaller subproblems and storing the solutions to avoid recomputing them. The key idea behind dynamic programming is to exploit the overlapping nature of subproblems to achieve efficient solutions.

The purpose of dynamic programming is to optimize the time and space complexity of algorithms by avoiding redundant computations. By storing the solutions to smaller subproblems, dynamic programming can reuse these solutions when solving larger subproblems, leading to a significant reduction in the overall computational effort.

## 2. Walkthrough of the Pattern's Implementation

Dynamic programming typically involves the following steps:

1. **Identify Subproblems**: The first step is to identify the smaller subproblems that make up the larger problem. This involves breaking down the problem into smaller, interrelated components that can be solved independently.

2. **Define Recurrence Relation**: Next, you need to establish a recurrence relation that describes how the solution to a larger problem can be constructed from the solutions to its smaller subproblems. This recurrence relation is the core of the dynamic programming approach.

3. **Implement Bottom-up Approach**: Dynamic programming uses a bottom-up approach, where you start by solving the simplest subproblems and then combine their solutions to solve larger subproblems. This is typically done using either a tabular (memoization) or a recursive (top-down) approach.

4. **Optimize Space Complexity**: Depending on the problem, you may need to optimize the space complexity of the dynamic programming solution. This can be done by using only the minimum amount of storage required to solve the problem, often by reusing or overwriting previous solutions.

Here's a simple example to illustrate the steps:

**Problem: Fibonacci Sequence**

The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1. The first few Fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

**Step 1: Identify Subproblems**
The subproblems in the Fibonacci sequence are the Fibonacci numbers themselves. To compute the nth Fibonacci number, we need to compute the (n-1)th and (n-2)th Fibonacci numbers.

**Step 2: Define Recurrence Relation**
The recurrence relation for the Fibonacci sequence is:
```
F(n) = F(n-1) + F(n-2)
```
where F(0) = 0 and F(1) = 1 are the base cases.

**Step 3: Implement Bottom-up Approach**
Using a tabular (memoization) approach, we can compute the Fibonacci numbers as follows:

```python
def fib(n):
    if n <= 1:
        return n
    
    fib_table = [0, 1]
    for i in range(2, n+1):
        fib_table.append(fib_table[i-1] + fib_table[i-2])
    return fib_table[n]
```

The key steps are:

1. Initialize a table `fib_table` with the base cases: `fib_table[0] = 0` and `fib_table[1] = 1`.
2. Use a loop to compute the remaining Fibonacci numbers, where `fib_table[i] = fib_table[i-1] + fib_table[i-2]`.
3. Return the nth Fibonacci number, which is stored in `fib_table[n]`.

**Step 4: Optimize Space Complexity**
The space complexity of the above solution is O(n), as it stores all the Fibonacci numbers in the `fib_table`. We can optimize this by only storing the last two Fibonacci numbers and updating them in each iteration:

```python
def fib(n):
    if n <= 1:
        return n
    
    prev, curr = 0, 1
    for _ in range(2, n+1):
        prev, curr = curr, prev + curr
    return curr
```

This optimized solution has a space complexity of O(1), as it only uses two variables to store the previous and current Fibonacci numbers.

## 3. Code Implementation

Here's the code implementation of the Fibonacci sequence using dynamic programming in Python:

```python
def fib(n):
    if n <= 1:
        return n
    
    fib_table = [0, 1]
    for i in range(2, n+1):
        fib_table.append(fib_table[i-1] + fib_table[i-2])
    return fib_table[n]
```

## 4. Applications of Dynamic Programming

Dynamic programming is a powerful technique that can be applied to a wide range of problems, including:

1. **Optimization Problems**: Dynamic programming is particularly useful for optimization problems, such as finding the shortest path, the maximum/minimum value, or the optimal way to perform a task.
   Examples: Knapsack problem, Longest Common Subsequence, Coin Change problem.

2. **Counting and Enumeration Problems**: Dynamic programming can be used to efficiently count or enumerate the number of solutions to a problem.
   Examples: Counting the number of ways to climb a staircase, Counting the number of binary trees.

3. **Decision-making Problems**: Dynamic programming can be used to make optimal decisions in sequential or multi-stage decision problems.
   Examples: Scheduling problems, Resource allocation problems.

4. **String and Array Problems**: Dynamic programming is often used to solve problems related to strings and arrays, such as finding the longest palindromic substring or the largest common subarray.
   Examples: Edit Distance, Longest Increasing Subsequence.

Dynamic programming is most effective when the problem exhibits the following characteristics:
- **Overlapping Subproblems**: The problem can be broken down into smaller subproblems, and these subproblems are repeated during the computation.
- **Optimal Substructure**: The optimal solution to the overall problem can be constructed from the optimal solutions to the subproblems.

## 5. Practice Problems

### Easy Problems

1. **Climbing Stairs**: https://leetcode.com/problems/climbing-stairs/
2. **House Robber**: https://leetcode.com/problems/house-robber/
3. **Fibonacci Number**: https://leetcode.com/problems/fibonacci-number/
4. **Minimum Cost Climbing Stairs**: https://leetcode.com/problems/minimum-cost-climbing-stairs/
5. **Coin Change**: https://leetcode.com/problems/coin-change/

### Medium Problems

1. **Longest Increasing Subsequence**: https://leetcode.com/problems/longest-increasing-subsequence/
2. **Minimum Path Sum**: https://leetcode.com/problems/minimum-path-sum/
3. **Partition Equal Subset Sum**: https://leetcode.com/problems/partition-equal-subset-sum/
4. **House Robber II**: https://leetcode.com/problems/house-robber-ii/
5. **Continuous Subarray Sum**: https://leetcode.com/problems/continuous-subarray-sum/

### Hard Problems

1. **Edit Distance**: https://leetcode.com/problems/edit-distance/
2. **Longest Common Subsequence**: https://leetcode.com/problems/longest-common-subsequence/
3. **Burst Balloons**: https://leetcode.com/problems/burst-balloons/
4. **Regular Expression Matching**: https://leetcode.com/problems/regular-expression-matching/
5. **Distinct Subsequences**: https://leetcode.com/problems/distinct-subsequences/
