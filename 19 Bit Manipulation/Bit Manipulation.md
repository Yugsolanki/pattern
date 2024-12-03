# Bit Manipulation

## 1. Concise Explanation

Bit manipulation is a technique that operates directly on the binary representation of numbers. It leverages bitwise operations to perform efficient computations, often reducing time and space complexity compared to traditional arithmetic operations.

## 2. Detailed Walkthrough

Bit manipulation typically involves the following operations:

1. **AND (&)**: Sets each bit to 1 if both bits are 1.
2. **OR (|)**: Sets each bit to 1 if at least one bit is 1.
3. **XOR (^)**: Sets each bit to 1 if exactly one bit is 1.
4. **NOT (~)**: Inverts all bits.
5. **Left Shift (<<)**: Shifts bits left, filling with 0s on the right.
6. **Right Shift (>>)**: Shifts bits right, filling with the sign bit on the left.

Let's walk through a common bit manipulation technique: using XOR to find a single number that appears only once in an array where all other numbers appear twice.

Example array: [4, 1, 2, 1, 2]

Steps:
1. Initialize result = 0
2. XOR each number in the array with result:
   - 0 ^ 4 = 4
   - 4 ^ 1 = 5
   - 5 ^ 2 = 7
   - 7 ^ 1 = 6
   - 6 ^ 2 = 4
3. The final result (4) is the number that appears only once.

This works because:
- XOR is commutative and associative
- A number XOR'd with itself is 0
- Any number XOR'd with 0 is itself

## 3. Code Implementation

Here's a Python implementation of the above example:

```python
def find_single_occurrence(nums):
    result = 0
    for num in nums:
        result ^= num
    return result

# Example usage
arr = [4, 1, 2, 1, 2]
print(find_single_occurrence(arr))  # Output: 4
```

## 4. Applications

Bit manipulation is useful for:

1. Optimizing space usage (e.g., using a single integer as a bitset)
2. Performing fast arithmetic operations
3. Implementing low-level system functions
4. Solving certain types of puzzles efficiently

It's most effective in scenarios where:
- Memory usage is critical
- Performance optimization is necessary
- Working with binary data or flags
- Implementing cryptographic algorithms

## 5. Practice Problems

### Easy Problems (Least to Most Important)

1. Check if a number is even or odd
2. Swap two numbers without using a temporary variable
3. Turn off the rightmost set bit
4. Compute XOR of all numbers from 1 to n
5. Find the position of the rightmost set bit
6. Check if a number is a power of 2
7. Count the number of set bits in an integer
8. Find the missing number in an array of n-1 integers (1 to n)
9. Detect if two integers have opposite signs
10. Find the only element appearing once in an array where every other element appears twice

### Medium Problems (Least to Most Important)

1. Reverse bits of a given integer
2. Find the two numbers appearing only once in an array where every other number appears twice
3. Calculate the parity of a number
4. Implement multiplication without using the * operator
5. Find the maximum subarray XOR in a given array
6. Count total set bits in all numbers from 1 to n
7. Divide two integers without using division, multiplication and mod operator
8. Find the longest sequence of 1's in binary representation of a number
9. Implement bitwise AND of numbers range
10. Find the number of bits needed to be flipped to convert A to B

### Difficult Problems (Least to Most Important)

1. Implement a bit array (set, clear, and test operations)
2. Find the smallest number with given number of set bits
3. Implement subtraction without using the - operator
4. Calculate square root without using sqrt function
5. Find the maximum subset XOR in a given set of integers
6. Implement a binary floating-point representation
7. Find the shortest unique prefix for every word in a given list
8. Implement arithmetic operations for rational numbers using bit manipulation
9. Design a bitwise-AND range query data structure
10. Implement an efficient algorithm for Gray code sequence generation
