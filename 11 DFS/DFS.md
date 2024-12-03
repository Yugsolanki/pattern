# Depth-First Search (DFS) Pattern

## 1. Concise Explanation and Purpose

The Depth-First Search (DFS) pattern is a fundamental algorithm used to explore a graph or tree data structure. It starts at a given node (the root or starting node) and exhaustively visits all the nodes it can reach by following the edges of the graph or tree, going as deep as possible before backtracking.

The purpose of the DFS pattern is to systematically traverse a graph or tree, enabling various operations such as:

- Searching for a specific node or value
- Detecting cycles in the graph
- Topological sorting
- Connected component analysis
- Solving problems that can be modeled as a graph or tree

## 2. Detailed Walkthrough

The DFS pattern typically involves the following steps:

1. **Initialize the search**: Start at a given node, which is often the root of a tree or the starting node of a graph.
2. **Mark the current node as visited**: To avoid revisiting the same node, maintain a data structure (e.g., a set or a boolean array) to keep track of the visited nodes.
3. **Explore the current node's neighbors**: For the current node, visit each of its unvisited neighboring nodes by recursively calling the DFS function on them.
4. **Backtrack**: When all the neighbors of the current node have been visited, return from the recursive call and continue the search from the previous node.

Here's a step-by-step walkthrough of the DFS algorithm on a simple graph:

```
Graph:
    A
   / \
  B   C
 / \   \
D   E   F
```

1. Start at node A (the root node).
2. Mark A as visited.
3. Explore A's neighbors:
   - Visit B (mark as visited)
     - Visit D (mark as visited)
     - Visit E (mark as visited)
   - Visit C (mark as visited)
     - Visit F (mark as visited)
4. All of A's neighbors have been visited, so the search backtracks.
5. The search is complete, and all reachable nodes have been visited.

The order in which the nodes are visited in this example is: A, B, D, E, C, F.

## 3. Code Implementation

Here's an implementation of the Depth-First Search (DFS) pattern in Python:

```python
from collections import defaultdict

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()

    visited.add(start)
    print(start)

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example usage
graph = defaultdict(list)
graph['A'] = ['B', 'C']
graph['B'] = ['D', 'E']
graph['C'] = ['F']
graph['D'] = []
graph['E'] = []
graph['F'] = []

dfs(graph, 'A')
```

In this implementation, the `dfs` function takes a graph represented as a dictionary (where the keys are nodes and the values are lists of neighboring nodes), a starting node, and an optional `visited` set to keep track of the visited nodes. The function recursively explores the graph, marking each visited node and printing the node's value.

## 4. Applications and Scenarios

**Applications:**
- Searching for a specific node or value in a graph or tree.
- Detecting cycles in a graph.
- Topological sorting of a directed acyclic graph (DAG).
- Finding connected components in an undirected graph.
- Solving problems that can be modeled as a graph or tree, such as maze solving, social network analysis, or network routing.

**Scenarios:**
- Navigating a file system directory structure, which can be represented as a tree.
- Exploring a decision-making process modeled as a decision tree.
- Analyzing the dependencies between tasks or activities in a project management system, which can be represented as a directed graph.
- Identifying the reach of influence in a social network, where each user is a node and the connections between users are the edges.

## 5. Practice Problems

### Easy
1. [LeetCode 200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
2. [LeetCode 733. Flood Fill](https://leetcode.com/problems/flood-fill/)
3. [LeetCode 695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
4. [LeetCode 1215. Stepping Numbers](https://leetcode.com/problems/stepping-numbers/)
5. [LeetCode 994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

### Medium
1. [LeetCode 130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)
2. [LeetCode 547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
3. [LeetCode 417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)
4. [LeetCode 1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)
5. [LeetCode 1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)

### Difficult
1. [LeetCode 269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
2. [LeetCode 329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
3. [LeetCode 691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/)
4. [LeetCode 839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/)
5. [LeetCode 1298. Maximum Candies Divided by Bags](https://leetcode.com/problems/maximum-candies-divided-by-bags/)