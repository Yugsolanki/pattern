# Prefix Sum

## 1. Concise Explanation and Purpose

The prefix sum pattern, also known as the cumulative sum or running sum pattern, is a technique used in data structures and algorithms to efficiently compute the cumulative sum of elements in an array or sequence. The primary purpose of this pattern is to precompute the running sums of array elements, which can then be used to quickly answer queries about the sum of a subarray or range within the original array.

## 2. Detailed Walkthrough

The prefix sum pattern involves two main steps:

1. **Preprocessing**: In this step, we create a new array (or data structure) that stores the cumulative sums of the original array elements. The first element of the prefix sum array is the same as the first element of the original array, and each subsequent element is the sum of the current element and the previous prefix sum.

2. **Query Processing**: After the prefix sum array has been constructed, we can use it to efficiently answer queries about the sum of a subarray or range within the original array. To do this, we simply need to subtract the prefix sum at the start of the range from the prefix sum at the end of the range (inclusive).

Here's a step-by-step walkthrough of the prefix sum pattern:

1. **Original Array**: Let's consider the following array as an example: `[1, 2, 3, 4, 5]`.

2. **Preprocessing**: To create the prefix sum array, we'll start with the first element and then add each subsequent element to the previous sum:
   * Prefix Sum Array: `[1, 3, 6, 10, 15]`

3. **Query Processing**: Suppose we want to find the sum of the subarray from index 1 to 3 (inclusive) in the original array. We can do this by subtracting the prefix sum at index 1 (which is 3) from the prefix sum at index 3 (which is 6):
   * Sum of subarray from index 1 to 3 = Prefix Sum at index 3 - Prefix Sum at index 1 = 6 - 3 = 3

This allows us to compute the sum of any subarray in the original array in constant time (O(1)), as opposed to having to iterate through the subarray and sum the elements, which would take linear time (O(n)).

## 3. Code Implementation

Here's an implementation of the prefix sum pattern in Python:

```python
def prefix_sum(nums):
    """
    Compute the prefix sum array from the given input array.
    
    Args:
        nums (List[int]): The input array of integers.
        
    Returns:
        List[int]: The prefix sum array.
    """
    prefix_sum_arr = [nums[0]]
    for i in range(1, len(nums)):
        prefix_sum_arr.append(prefix_sum_arr[-1] + nums[i])
    return prefix_sum_arr

def subarray_sum(prefix_sum, left, right):
    """
    Compute the sum of the subarray from index `left` to `right` (inclusive)
    using the prefix sum array.
    
    Args:
        prefix_sum (List[int]): The prefix sum array.
        left (int): The left index of the subarray.
        right (int): The right index of the subarray.
        
    Returns:
        int: The sum of the subarray from index `left` to `right` (inclusive).
    """
    if left == 0:
        return prefix_sum[right]
    else:
        return prefix_sum[right] - prefix_sum[left - 1]
```

## 4. Applications and Scenarios

The prefix sum pattern is useful in a wide range of problems, particularly those that involve:

1. **Range Queries**: Computing the sum, minimum, maximum, or any other aggregation of elements within a subarray or range in an array.
2. **Frequency Counting**: Tracking the cumulative frequency or count of elements in an array, which can be useful for problems like histogram construction.
3. **Geometric Computations**: Calculating the area or volume of shapes represented by discrete data points.
4. **Dynamic Programming**: The prefix sum array can serve as a memoization structure, enabling efficient solutions to dynamic programming problems.

The prefix sum pattern is most effective when you need to answer multiple queries about subarrays or ranges within a fixed array, as the preprocessing step allows for efficient query processing.

## 5. Practice Problems

Here are some practice problems to reinforce your understanding of the prefix sum pattern:

Easy:
1. [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
2. [Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)
3. [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
4. [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)
5. [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

Medium:
1. [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)
2. [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)
3. [Subarray Sum Ranges](https://leetcode.com/problems/subarray-sum-ranges/)
4. [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)
5. [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

Hard:
1. [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/)
2. [Maximum Sum of Rectangular Submatrix in Matrix](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)
3. [Paint House II](https://leetcode.com/problems/paint-house-ii/)
4. [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/)
5. [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)