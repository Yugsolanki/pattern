# Union-Find (Disjoint Set)

## 1. **Concise Explanation of the Pattern**

**Union-Find (Disjoint Set)** is a data structure used to keep track of a partition of a set into disjoint (non-overlapping) subsets. It provides two primary operations:
1. **Find**: Determines which subset a particular element is in. This can be used to check if two elements are in the same subset.
2. **Union**: Merges two subsets into a single subset.

This pattern is useful for solving problems where we need to keep track of connected components or equivalently determine the connectivity of a system. It is often used in graph-related problems like finding connected components, cycle detection, and Kruskal's Minimum Spanning Tree algorithm.

## 2. **Detailed Walkthrough of the Pattern's Implementation**

### Key Components

1. **Parent Array**: Each element points to another element that represents its "parent" in the set. For an element that is the root of its set, its parent is itself.
2. **Rank/Size Array**: Keeps track of the depth (rank) or the size of the tree for efficiency. This helps in determining which root should become the parent during a union operation.

### Steps for Implementation

1. **Initialization**:  
   Each element starts as its own parent, i.e., each element is in its own set. The rank or size of each set is initialized to 1.

2. **Find Operation**:  
   The `find` operation locates the representative (or root) of the set containing an element. This can be done by traversing the parent array until we reach an element that is its own parent (the root). Path compression is used to speed up future operations by pointing all traversed elements directly to the root.

3. **Union Operation**:  
   The `union` operation merges two sets. It first finds the roots of both sets using `find`, and then attaches the smaller tree under the root of the larger tree to maintain balance. This is called union by rank (or size).

### Step-by-Step Walkthrough

**Example**: Let's say we have a set of 5 elements `{0, 1, 2, 3, 4}` and perform the following operations:
1. `Union(0, 1)`
2. `Union(2, 3)`
3. `Union(1, 2)`

- **Initial Setup**:  
   - Parent: `[0, 1, 2, 3, 4]` (Each element is its own parent)
   - Rank: `[1, 1, 1, 1, 1]` (Each element starts with rank 1)

- **Union(0, 1)**:  
   - Find root of `0`: `0`  
   - Find root of `1`: `1`  
   - Union: Attach root of `1` under root of `0` since they are of equal rank (update rank of `0`).  
   - Parent: `[0, 0, 2, 3, 4]`  
   - Rank: `[2, 1, 1, 1, 1]`

- **Union(2, 3)**:  
   - Find root of `2`: `2`  
   - Find root of `3`: `3`  
   - Union: Attach root of `3` under root of `2`.  
   - Parent: `[0, 0, 2, 2, 4]`  
   - Rank: `[2, 1, 2, 1, 1]`

- **Union(1, 2)**:  
   - Find root of `1`: Traverse to root `0` (Path Compression makes `1` point to `0` directly).  
   - Find root of `2`: `2`  
   - Union: Attach root of `2` under root of `0` (since rank of `0` is higher).  
   - Parent: `[0, 0, 0, 2, 4]`  
   - Rank: `[3, 1, 2, 1, 1]`

Now, elements `0`, `1`, `2`, and `3` belong to the same set (with `0` as the root), and element `4` is in its own set.

## 3. **Code Implementation**

Here’s the implementation of the Union-Find (Disjoint Set) in Python:

```python
class UnionFind:
    def __init__(self, n):
        # Initially, each element is its own parent, and rank is 1
        self.parent = [i for i in range(n)]
        self.rank = [1] * n
    
    def find(self, x):
        # Path compression: Make the parent of x point directly to the root
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        # Find the roots of x and y
        rootX = self.find(x)
        rootY = self.find(y)
        
        # If they are already in the same set, do nothing
        if rootX == rootY:
            return
        
        # Union by rank: Attach the smaller tree under the larger tree
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1

# Example usage
uf = UnionFind(5)  # Create a UnionFind for 5 elements (0 to 4)
uf.union(0, 1)
uf.union(2, 3)
uf.union(1, 2)

# Find roots of elements to check connectivity
print("Find(0):", uf.find(0))  # Output: 0
print("Find(3):", uf.find(3))  # Output: 0
print("Find(4):", uf.find(4))  # Output: 4 (element 4 is in its own set)
```

## 4. **Applications of the Union-Find Pattern**

### Types of Problems It Can Solve:
1. **Dynamic Connectivity**: Union-Find is useful when you need to dynamically connect elements and query whether two elements are connected.
2. **Cycle Detection in Undirected Graphs**: Union-Find can efficiently detect cycles in an undirected graph.
3. **Kruskal's Algorithm**: Used for finding the Minimum Spanning Tree of a graph.
4. **Network Connectivity**: Modeling connectivity problems (like social networks or electrical grids).
5. **Percolation Problems**: Used in physics and simulations to determine connected components in a grid.

### Scenarios Where It’s Most Effective:
- **Sparse Graphs**: Union-Find is very effective in scenarios where graph operations are performed sparsely (like adding edges dynamically).
- **Dynamic Set Merging**: When you need to repeatedly merge sets and query their connectedness over time.
- **Efficient Connectivity Queries**: When you need to answer many "are these elements connected?" queries efficiently.

## 5. **Practice Problems to Reinforce Understanding**

### **Easy Problems**
1. **Connected Components**: Given a graph, find the number of connected components using Union-Find.
2. **Friend Circles**: Given a matrix of friendships, find how many friend circles exist.
3. **Detect Cycle in an Undirected Graph**: Use Union-Find to detect cycles in an undirected graph.
4. **Union of Two Sets**: Implement basic Union and Find operations on two sets.
5. **Check if Two Elements Are in the Same Set**: Implement a function that checks if two elements belong to the same set.

### **Medium Problems**
1. **Redundant Connection**: Given a graph, find the edge that can be removed to make the graph acyclic.
2. **Number of Islands**: Use Union-Find to find the number of islands in a grid of land and water.
3. **Connecting Cities with Minimum Cost**: Use Kruskal’s algorithm to connect all cities with the minimum cost.
4. **Evaluate Division**: Given a set of equations, evaluate division queries using Union-Find.
5. **Account Merging**: Merge multiple accounts with the same email addresses using Union-Find.

### **Difficult Problems**
1. **Swim in Rising Water**: Find the minimum time required to swim from the top-left to bottom-right corner of a grid, where the water level rises at different times.
2. **Largest Component Size by Common Factor**: Group numbers that share at least one prime factor using Union-Find.
3. **Minimum Spanning Tree in a Dynamic Graph**: Maintain the minimum spanning tree as edges are added to a graph.
4. **Percolation Problem**: Simulate the percolation of water through a grid using Union-Find.
5. **Dynamic Connectivity Problem**: Maintain connectivity information in a dynamically changing graph with additions and deletions of edges.
