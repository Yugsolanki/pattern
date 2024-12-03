# Tree Traversal Pattern

## 1. Concise Explanation and Purpose

The tree traversal pattern is a fundamental technique for exploring and processing the nodes of a tree data structure. It involves visiting each node in a specific order, which can be classified into three main types:

1. **Depth-First Traversal**: Visits the current node, then the left subtree, and finally the right subtree (pre-order), or the left subtree, then the current node, and finally the right subtree (in-order), or the left subtree, then the right subtree, and finally the current node (post-order).
2. **Breadth-First Traversal**: Visits all the nodes at the current level before moving on to the next level.
3. **Iterative Traversal**: Performs a depth-first traversal using an explicit stack or queue data structure, without using recursion.

The purpose of the tree traversal pattern is to provide a systematic way to access and process the elements of a tree data structure, enabling various operations such as searching, sorting, and transforming the data.

## 2. Detailed Walkthrough

Let's dive into the implementation details for each of the three main tree traversal approaches:

### Depth-First Traversal

1. **Pre-order Traversal**:
   - Visit the current node.
   - Recursively traverse the left subtree.
   - Recursively traverse the right subtree.

2. **In-order Traversal**:
   - Recursively traverse the left subtree.
   - Visit the current node.
   - Recursively traverse the right subtree.

3. **Post-order Traversal**:
   - Recursively traverse the left subtree.
   - Recursively traverse the right subtree.
   - Visit the current node.

### Breadth-First Traversal (Level-Order Traversal)

1. Initialize an empty queue.
2. Enqueue the root node.
3. While the queue is not empty:
   - Dequeue a node from the front of the queue.
   - Visit the dequeued node.
   - If the dequeued node has a left child, enqueue the left child.
   - If the dequeued node has a right child, enqueue the right child.

### Iterative Depth-First Traversal

1. **Pre-order Traversal**:
   - Initialize an empty stack.
   - Push the root node onto the stack.
   - While the stack is not empty:
     - Pop a node from the stack.
     - Visit the popped node.
     - If the node has a right child, push the right child onto the stack.
     - If the node has a left child, push the left child onto the stack.

2. **In-order Traversal**:
   - Initialize an empty stack.
   - While the current node is not null or the stack is not empty:
     - While the current node is not null:
       - Push the current node onto the stack.
       - Move to the left child of the current node.
     - Pop a node from the stack.
     - Visit the popped node.
     - Move to the right child of the popped node.

3. **Post-order Traversal**:
   - Initialize an empty stack.
   - Push the root node onto the stack.
   - Initialize a variable `prev` to keep track of the previously visited node.
   - While the stack is not empty:
     - Get the top node from the stack.
     - If the top node has no children or the top node's children are the same as `prev`:
       - Pop the top node from the stack.
       - Visit the popped node.
       - Update `prev` to the popped node.
     - Else:
       - If the top node has a right child, push the right child onto the stack.
       - If the top node has a left child, push the left child onto the stack.

## 3. Code Implementation

Here's an implementation of the tree traversal pattern in Python:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def preorder_traversal(root):
    def dfs(node):
        if node:
            result.append(node.val)
            dfs(node.left)
            dfs(node.right)
    result = []
    dfs(root)
    return result

def inorder_traversal(root):
    def dfs(node):
        if node:
            dfs(node.left)
            result.append(node.val)
            dfs(node.right)
    result = []
    dfs(root)
    return result

def postorder_traversal(root):
    def dfs(node):
        if node:
            dfs(node.left)
            dfs(node.right)
            result.append(node.val)
    result = []
    dfs(root)
    return result

def levelorder_traversal(root):
    if not root:
        return []
    queue = [root]
    result = []
    while queue:
        level_size = len(queue)
        level_nodes = []
        for _ in range(level_size):
            node = queue.pop(0)
            level_nodes.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        result.append(level_nodes)
    return result
```

## 4. Applications and Scenarios

**Applications:**
- Searching for a specific node or value in a tree.
- Performing transformations or modifications on the tree structure.
- Serializing and deserializing tree data structures.
- Implementing tree-based algorithms, such as sorting, indexing, or pathfinding.

**Scenarios:**
- Navigating a file system directory tree.
- Traversing an organizational hierarchy represented as a tree.
- Exploring a decision-making process modeled as a decision tree.
- Analyzing the structure of an XML or HTML document, which can be represented as a tree.

## 5. Practice Problems

### Easy
1. [LeetCode 94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
2. [LeetCode 144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
3. [LeetCode 145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)
4. [LeetCode 102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
5. [LeetCode 429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

### Medium
1. [LeetCode 199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
2. [LeetCode 107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
3. [LeetCode 103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
4. [LeetCode 450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)
5. [LeetCode 113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)

### Difficult
1. [LeetCode 297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
2. [LeetCode 124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
3. [LeetCode 987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
4. [LeetCode 1110. Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)
5. [LeetCode 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)