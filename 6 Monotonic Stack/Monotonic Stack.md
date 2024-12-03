# Monotonic Stack Pattern

## 1. Concise Explanation and Purpose

The monotonic stack pattern is a technique used in data structures and algorithms to efficiently solve problems that involve finding the nearest element (to the left or right) in an array or a sequence that satisfies a certain condition. The key idea behind this pattern is to maintain a stack of elements that is either strictly increasing or strictly decreasing, allowing for quick lookups and updates.

The primary purpose of the monotonic stack pattern is to provide an efficient solution to problems that require finding the nearest element in an array or sequence that meets a specific criterion, such as the nearest greater or smaller element, the nearest element with a certain property, or the nearest element that satisfies a given constraint.

## 2. Detailed Walkthrough

The monotonic stack pattern typically involves the following steps:

1. **Initialization**: Create an empty stack to store the elements.

2. **Traversal**: Iterate through the array or sequence, processing each element one by one.

3. **Stack Manipulation**: For each element, perform the following operations:
   - If the stack is empty or the current element satisfies the desired condition with respect to the top of the stack, push the current element onto the stack.
   - If the current element does not satisfy the desired condition with respect to the top of the stack, repeatedly pop elements from the stack until the condition is met. Then, push the current element onto the stack.

4. **Result Extraction**: After processing all the elements, the stack will contain the desired information, such as the indices or values of the nearest elements that satisfy the given condition.

Here's a step-by-step walkthrough of the monotonic stack pattern using an example problem:

**Problem**: Given an array of integers, find the nearest greater element to the right of each element.

1. **Initialization**: Create an empty stack.

2. **Traversal**: Iterate through the array from right to left.

3. **Stack Manipulation**:
   - Iteration 1 (for the rightmost element): The stack is empty, so push the rightmost element onto the stack.
   - Iteration 2: The current element is smaller than the top of the stack, so repeatedly pop elements from the stack until the condition is met (i.e., the top of the stack is smaller than the current element). Then, push the current element onto the stack.
   - Iteration 3: The current element is smaller than the top of the stack, so repeatedly pop elements from the stack until the condition is met. Then, push the current element onto the stack.
   - Iteration 4: The current element is greater than the top of the stack, so push the current element onto the stack.

4. **Result Extraction**: After processing all the elements, the stack will contain the indices or values of the nearest greater elements to the right of each element in the original array.

By maintaining a monotonic stack (either strictly increasing or strictly decreasing), the algorithm can efficiently find the nearest element that satisfies the given condition, without the need to repeatedly search through the entire array.

## 3. Code Implementation

Here's an implementation of the monotonic stack pattern in Python to find the nearest greater element to the right of each element in an array:

```python
def nearest_greater_element(nums):
    """
    Find the nearest greater element to the right of each element in the array.
    
    Args:
        nums (List[int]): The input array of integers.
        
    Returns:
        List[int]: The list of nearest greater elements to the right of each element.
    """
    stack = []
    result = [-1] * len(nums)
    
    for i in range(len(nums) - 1, -1, -1):
        while stack and stack[-1] <= nums[i]:
            stack.pop()
        if stack:
            result[i] = stack[-1]
        stack.append(nums[i])
    
    return result
```

In this implementation, we iterate through the array from right to left. For each element, we pop elements from the stack until we find an element that is greater than the current element. We then store the index of the greater element in the `result` array, and push the current element onto the stack.

After processing all the elements, the `result` array will contain the indices of the nearest greater elements to the right of each element in the original array.

## 4. Applications and Scenarios

The monotonic stack pattern is particularly useful in the following scenarios:

1. **Finding Nearest Greater/Smaller Elements**: Solving problems that require finding the nearest element (to the left or right) in an array or sequence that satisfies a certain condition, such as the nearest greater or smaller element.

2. **Stock Span Problem**: Calculating the number of consecutive days for which the stock price is less than or equal to the current day's stock price.

3. **Histogram-related Problems**: Solving problems that involve processing histograms, such as finding the largest rectangle in a histogram or the largest area under a skyline.

4. **Array/String Manipulation**: Applying the monotonic stack pattern to solve problems that involve manipulating arrays or strings, such as finding the length of the longest valid parentheses or the next greater element.

The monotonic stack pattern is most effective when the problem requires efficiently finding the nearest element that satisfies a specific condition, as the stack structure allows for quick lookups and updates.

## 5. Practice Problems

Here are some practice problems to reinforce your understanding of the monotonic stack pattern:

Easy:
1. [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
2. [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
3. [Nearest Greater Element](https://www.geeksforgeeks.org/find-the-nearest-greater-element/)
4. [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
5. [Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

Medium:
1. [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)
2. [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)
3. [Monotone Increasing Digits](https://leetcode.com/problems/monotone-increasing-digits/)
4. [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
5. [Maximum Sum Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

Hard:
1. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
2. [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
3. [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
4. [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
5. [Exclusive Time of Functions](https://leetcode.com/problems/exclusive-time-of-functions/)
