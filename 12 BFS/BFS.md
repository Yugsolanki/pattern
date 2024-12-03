# Breadth-First Search (BFS) Pattern

## 1. Concise Explanation and Purpose

The Breadth-First Search (BFS) pattern is an algorithm used to explore a graph or tree data structure. Unlike Depth-First Search (DFS), which visits all the nodes at a given depth before moving on to the next depth level, BFS visits all the nodes at the current depth level before moving on to the next level.

The purpose of the BFS pattern is to systematically traverse a graph or tree, enabling various operations such as:

- Finding the shortest path between two nodes in an unweighted graph
- Identifying the level or depth of a node in a tree
- Solving problems that can be modeled as a graph or tree, where the solution requires visiting nodes in a level-by-level fashion

## 2. Detailed Walkthrough

The BFS pattern typically involves the following steps:

1. **Initialize the search**: Start at a given node, which is often the root of a tree or the starting node of a graph.
2. **Create a queue**: Use a queue data structure to keep track of the nodes to be visited.
3. **Enqueue the starting node**: Add the starting node to the queue.
4. **Process the queue**: While the queue is not empty:
   - Dequeue a node from the front of the queue.
   - Mark the dequeued node as visited.
   - Enqueue all the unvisited neighbors of the dequeued node.
5. **Repeat**: Continue the process until the queue is empty, indicating that all reachable nodes have been visited.

Here's a step-by-step walkthrough of the BFS algorithm on a simple graph:

```
Graph:
    A
   / \
  B   C
 / \   \
D   E   F
```

1. Start at node A (the root node).
2. Create a queue and enqueue A.
3. Dequeue A from the queue. Mark A as visited.
4. Enqueue B and C (A's neighbors) to the queue.
5. Dequeue B from the queue. Mark B as visited.
6. Enqueue D and E (B's neighbors) to the queue.
7. Dequeue C from the queue. Mark C as visited.
8. Enqueue F (C's neighbor) to the queue.
9. Dequeue D from the queue. Mark D as visited.
10. Dequeue E from the queue. Mark E as visited.
11. Dequeue F from the queue. Mark F as visited.
12. The queue is now empty, and all reachable nodes have been visited.

The order in which the nodes are visited in this example is: A, B, C, D, E, F.

## 3. Code Implementation

Here's an implementation of the Breadth-First Search (BFS) pattern in Python:

```python
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        node = queue.popleft()
        print(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

bfs(graph, 'A')
```

In this implementation, the `bfs` function takes a graph represented as a dictionary (where the keys are nodes and the values are lists of neighboring nodes) and a starting node. The function uses a queue to keep track of the nodes to be visited and a `visited` set to avoid revisiting nodes. It dequeues nodes from the front of the queue, marks them as visited, and enqueues their unvisited neighbors.

## 4. Applications and Scenarios

**Applications:**
- Finding the shortest path between two nodes in an unweighted graph.
- Identifying the level or depth of a node in a tree.
- Solving problems that can be modeled as a graph or tree, where the solution requires visiting nodes in a level-by-level fashion.
- Implementing breadth-first traversal of a tree data structure.

**Scenarios:**
- Navigating a maze or grid-based environment, where the goal is to find the shortest path from a starting point to a destination.
- Simulating the spread of a disease or information through a social network, where each person is a node and the connections between people are the edges.
- Organizing tasks or activities in a project management system, where the dependencies between tasks can be represented as a graph.
- Analyzing the structure of a file system directory tree, where the directories are nodes and the subdirectories are edges.

## 5. Practice Problems

### Easy
1. [LeetCode 102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
2. [LeetCode 993. Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/)
3. [LeetCode 1160. Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)
4. [LeetCode 1162. As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)
5. [LeetCode 1429. First Unique Number](https://leetcode.com/problems/first-unique-number/)

### Medium
1. [LeetCode 107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
2. [LeetCode 103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
3. [LeetCode 207. Course Schedule](https://leetcode.com/problems/course-schedule/)
4. [LeetCode 815. Bus Routes](https://leetcode.com/problems/bus-routes/)
5. [LeetCode 1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

### Difficult
1. [LeetCode 126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)
2. [LeetCode 269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
3. [LeetCode 675. Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)
4. [LeetCode 864. Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)
5. [LeetCode 1203. Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)