# Reservoir Sampling

## 1. Concise Explanation

Reservoir Sampling is a randomized algorithm for selecting a fixed-size sample from a population of unknown or large size, especially useful when dealing with data streams. It ensures that each item in the data stream has an equal probability of being selected in the final sample, regardless of its position in the stream.

## 2. Detailed Walkthrough

### Basic Algorithm (selecting k items from a stream):

1. Initialize an array `reservoir` of size k with the first k items from the stream.
2. For each subsequent item i (where i > k):
   a. Generate a random number j between 1 and i (inclusive).
   b. If j <= k, replace the item at reservoir[j-1] with the current item.

### Step-by-step Example:

Let's sample 3 items from the stream [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].

1. Initialize reservoir: [1, 2, 3]

2. Process remaining items:
   - i = 4:
     * Generate random j (1 to 4): say j = 2
     * j <= k, so replace: [1, 4, 3]
   - i = 5:
     * Generate random j (1 to 5): say j = 5
     * j > k, no change: [1, 4, 3]
   - i = 6:
     * Generate random j (1 to 6): say j = 1
     * j <= k, so replace: [6, 4, 3]
   ...continue for remaining items...

3. Final sample might be: [6, 8, 3]

### Probability Analysis:

- For any item, the probability of being in the final sample is k/n, where n is the total number of items processed.
- This holds true regardless of the item's position in the stream.

## 3. Code Implementation

Here's a Python implementation of Reservoir Sampling:

```python
import random

def reservoir_sampling(stream, k):
    reservoir = []
    
    # Fill the reservoir with first k items
    for i in range(k):
        reservoir.append(next(stream))
    
    # Process remaining items
    for i, item in enumerate(stream, start=k+1):
        j = random.randint(1, i)
        if j <= k:
            reservoir[j-1] = item
    
    return reservoir

# Example usage
def stream_generator():
    for i in range(1, 1000001):  # Simulating a large stream
        yield i

sample_size = 5
result = reservoir_sampling(stream_generator(), sample_size)
print(f"Sample of {sample_size} items:", result)
```

## 4. Applications

Reservoir Sampling is useful for:

1. Sampling from data streams of unknown or infinite length
2. Selecting a random subset from a large dataset without loading it entirely into memory
3. Maintaining a representative sample as new data arrives
4. Online machine learning algorithms that need to maintain a fixed-size training set

It's most effective when:
- The total size of the data is unknown or very large
- You need to process data in a single pass
- Memory constraints prevent storing the entire dataset
- You need to maintain a running sample that represents the entire stream at any point

## 5. Practice Problems

### Easy:
1. Implement reservoir sampling for a fixed-size array
2. Sample k unique numbers from 1 to n
3. Implement weighted reservoir sampling with a single item
4. Print a random line from a file that's too big to fit in memory
5. Randomly shuffle an array

### Medium:
1. Implement weighted reservoir sampling
2. Sample k items from n sorted streams
3. Implement reservoir sampling for a linked list
4. Design a data structure for sampling from a data stream with deletions
5. Implement a distributed reservoir sampling algorithm

### Hard:
1. Implement time-based reservoir sampling
2. Design an algorithm for reservoir sampling on a sliding window
3. Implement multi-reservoir sampling (sampling for multiple queries simultaneously)
4. Develop a reservoir sampling algorithm that minimizes random number generation
5. Implement reservoir sampling for graph streams
