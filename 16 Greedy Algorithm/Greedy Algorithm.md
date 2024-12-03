# Greedy Algorithm 

## 1. Concise Explanation

Greedy algorithms make locally optimal choices at each step, aiming to find a global optimum. They're efficient but don't always guarantee the best overall solution.

## 2. Detailed Walkthrough

Greedy algorithms typically follow this process:

1. Initialize the solution (often empty).
2. Define a selection function to choose the best candidate.
3. Define a feasibility function to check if a candidate can be used.
4. Define an objective function to assign a value to a solution.
5. While candidates remain:
   a. Select the best candidate.
   b. If the candidate is feasible, add it to the solution.
6. Return the solution.

Let's walk through a simple example: coin change problem (minimize number of coins for a given amount).

Given coins: [25, 10, 5, 1] cents
Amount: 63 cents

Steps:
1. Initialize solution: []
2. Select largest coin ≤ remaining amount: 25
3. Add to solution: [25]
4. Remaining amount: 63 - 25 = 38
5. Select largest coin ≤ 38: 25
6. Add to solution: [25, 25]
7. Remaining amount: 38 - 25 = 13
8. Select largest coin ≤ 13: 10
9. Add to solution: [25, 25, 10]
10. Remaining amount: 13 - 10 = 3
11. Select largest coin ≤ 3: 1
12. Add to solution: [25, 25, 10, 1, 1, 1]
13. Remaining amount: 0, algorithm terminates

Final solution: [25, 25, 10, 1, 1, 1] (6 coins)

## 3. Code Implementation

Here's a Python implementation of the coin change problem using a greedy approach:

```python
def greedy_coin_change(coins, amount):
    coins.sort(reverse=True)  # Sort coins in descending order
    result = []
    for coin in coins:
        while amount >= coin:
            result.append(coin)
            amount -= coin
    return result

# Example usage
coins = [25, 10, 5, 1]
amount = 63
solution = greedy_coin_change(coins, amount)
print(f"Coins used: {solution}")
print(f"Total coins: {len(solution)}")
```

## 4. Applications

Greedy algorithms are useful for:
- Optimization problems
- Problems with local optimal structure

Effective scenarios:
- Huffman coding for data compression
- Dijkstra's algorithm for shortest paths
- Kruskal's algorithm for minimum spanning trees
- Activity selection problems
- Fractional knapsack problem

## 5. Practice Problems

### Easy
1. Minimum number of coins for change (as demonstrated)
2. Maximum number of non-overlapping intervals
3. Fractional knapsack problem
4. Activity selection problem
5. Minimum platforms required for a railway station

### Medium
1. Job sequencing problem with deadlines
2. Huffman coding
3. Minimum number of refueling stops
4. Maximum length chain of pairs
5. Minimum number of arrows to burst balloons

### Difficult
1. Minimum number of meetings rooms
2. Minimum cost to connect all cities
3. Maximum profit in job scheduling
4. Candy distribution problem
5. Reorganize string (no two adjacent characters are the same)