# Hash Table (Hash Map) 

## 1. Concise Explanation

Hash tables are data structures that implement an associative array abstract data type, a structure that can map keys to values. They use a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. Hash tables provide efficient insertion, deletion, and lookup operations, typically achieving average time complexity of O(1) for these operations.

## 2. Detailed Walkthrough

### Key Components:
1. Hash Function: Converts keys into array indices
2. Array: Stores key-value pairs
3. Collision Resolution: Handles cases when multiple keys hash to the same index

### Operations:

#### Insertion:
1. Compute the hash of the key
2. Use the hash to determine the index in the array
3. If the slot is empty, insert the key-value pair
4. If occupied, use collision resolution (e.g., chaining or open addressing)

#### Lookup:
1. Compute the hash of the key
2. Find the corresponding index in the array
3. If the slot is empty, the key doesn't exist
4. If occupied, compare the stored key with the search key
5. If keys match, return the value; otherwise, use collision resolution to continue searching

#### Deletion:
1. Find the key using the lookup procedure
2. If found, remove the key-value pair
3. Handle any necessary adjustments for collision resolution

### Step-by-step Example:

Let's insert the following key-value pairs: (5, "apple"), (2, "banana"), (9, "cherry"), (5, "date")

Assume our hash function is h(k) = k % 7 and we're using chaining for collision resolution.

1. Insert (5, "apple"):
   - h(5) = 5 % 7 = 5
   - Insert at index 5

2. Insert (2, "banana"):
   - h(2) = 2 % 7 = 2
   - Insert at index 2

3. Insert (9, "cherry"):
   - h(9) = 9 % 7 = 2
   - Collision at index 2, chain with (2, "banana")

4. Insert (5, "date"):
   - h(5) = 5 % 7 = 5
   - Collision at index 5, chain with (5, "apple")

Final structure:
```
0: 
1: 
2: (2, "banana") -> (9, "cherry")
3: 
4: 
5: (5, "apple") -> (5, "date")
6: 
```

## 3. Code Implementation

Here's a Python implementation of a hash table using chaining:

```python
class HashNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
    
    def _hash(self, key):
        return hash(key) % self.size
    
    def insert(self, key, value):
        index = self._hash(key)
        if not self.table[index]:
            self.table[index] = HashNode(key, value)
        else:
            current = self.table[index]
            while current:
                if current.key == key:
                    current.value = value
                    return
                if not current.next:
                    current.next = HashNode(key, value)
                    return
                current = current.next
    
    def get(self, key):
        index = self._hash(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        raise KeyError(key)
    
    def remove(self, key):
        index = self._hash(key)
        if not self.table[index]:
            raise KeyError(key)
        if self.table[index].key == key:
            self.table[index] = self.table[index].next
            return
        current = self.table[index]
        while current.next:
            if current.next.key == key:
                current.next = current.next.next
                return
            current = current.next
        raise KeyError(key)

# Example usage
ht = HashTable(7)
ht.insert(5, "apple")
ht.insert(2, "banana")
ht.insert(9, "cherry")
ht.insert(5, "date")

print(ht.get(5))  # Output: date
ht.remove(2)
try:
    ht.get(2)
except KeyError:
    print("Key 2 not found")  # This will be printed
```

## 4. Applications

Hash tables are widely used for:
1. Implementing associative arrays (dictionaries)
2. Database indexing
3. Caches
4. Set data structures
5. Symbol tables in compilers and interpreters

They are most effective when:
- Fast insertion, deletion, and lookup are required
- The data has unique keys
- The hash function distributes keys uniformly
- Memory usage is not a primary concern

## 5. Practice Problems

### Easy:
1. Implement a basic hash table with linear probing
2. Find the first non-repeating character in a string
3. Check if two strings are anagrams
4. Implement a simple LRU cache
5. Count the frequency of words in a sentence

### Medium:
1. Implement a hash table with double hashing
2. Design a data structure for LRU cache
3. Find all pairs of integers in an array that sum to a given value
4. Implement a hash table that supports get, set, and setAll operations
5. Design a HashSet without using any built-in hash table libraries

### Hard:
1. Implement a concurrent hash map
2. Design a data structure to find median from a stream of numbers
3. Implement a distributed cache with consistent hashing
4. Design a real-time analytics system using probabilistic data structures (e.g., Count-Min Sketch)
5. Implement a perfect hashing scheme for static data