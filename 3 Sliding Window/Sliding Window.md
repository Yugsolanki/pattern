# Sliding Window Pattern

## 1. Concise Explanation and Purpose

The sliding window pattern is a technique used in data structures and algorithms to solve problems that involve finding a subarray, substring, or subrange that satisfies a specific condition or property. The core idea of this pattern is to maintain a "window" of elements that slides or moves through the data structure, updating the window as needed to find the desired solution.

The primary purpose of the sliding window pattern is to efficiently solve problems that require finding a subarray, substring, or subrange within a larger data structure, such as an array or a string. It is particularly useful for problems that involve finding the maximum, minimum, or average of a subarray, or problems that require finding a subarray that satisfies a certain condition.

## 2. Detailed Walkthrough

The sliding window pattern typically involves the following steps:

1. **Initialization**: Set up two pointers, often named "left" and "right", to define the initial window within the data structure.

2. **Window Expansion**: Expand the window by incrementing the "right" pointer, updating the window's contents as necessary.

3. **Condition Checking**: During the window expansion, check if the current window satisfies the problem's specific condition or requirement.

4. **Window Contraction**: If the current window does not satisfy the condition, contract the window by incrementing the "left" pointer, updating the window's contents as necessary.

5. **Result Extraction**: Once the desired window is found, extract the relevant information or result from the current window.

Here's a step-by-step walkthrough of the sliding window pattern using an example problem:

**Problem**: Given a string `s` and an integer `k`, find the length of the longest substring of `s` that contains at most `k` distinct characters.<br>
Example: 
<br>Input: `s = "eceba"`, `k = 2`
<br>Output: `3` (the longest substring with at most 2 distinct characters is "ece" where e appears twice and c appears once).

1. **Initialization**: Set two pointers, `left` and `right`, to the beginning of the string `s`. Also, maintain a dictionary or a hash map to keep track of the frequency of each character in the current window.

2. **Window Expansion**: Increment the `right` pointer and update the frequency map accordingly. If the number of distinct characters in the current window is greater than `k`, continue to the next step.

3. **Condition Checking**: Check if the number of distinct characters in the current window is greater than `k`. If so, proceed to the next step.

4. **Window Contraction**: Increment the `left` pointer and update the frequency map accordingly. If the number of distinct characters in the current window is now less than or equal to `k`, return to the previous step.

5. **Result Extraction**: Keep track of the maximum length of the window that satisfies the condition (i.e., contains at most `k` distinct characters). Return this maximum length as the final result.

By maintaining the sliding window and updating its contents as we move the pointers, we can efficiently find the longest substring that satisfies the given condition.

## 3. Code Implementation

Here's an implementation of the sliding window pattern in Python to solve the problem of finding the length of the longest substring with at most `k` distinct characters:

```python
def longest_substring_with_at_most_k_distinct(s, k):
    """
    Given a string `s` and an integer `k`, find the length of the longest substring of `s`
    that contains at most `k` distinct characters.
    
    Args:
        s (str): The input string.
        k (int): The maximum number of distinct characters allowed in the substring.
        
    Returns:
        int: The length of the longest substring of `s` that contains at most `k` distinct characters.
    """
    left, right = 0, 0
    char_freq = {}
    max_length = 0

    while right < len(s):
        # Expand the window by adding the current character
        char_freq[s[right]] = char_freq.get(s[right], 0) + 1

        # If the number of distinct characters is greater than k,
        # contract the window by removing characters from the left
        while len(char_freq) > k:
            char_freq[s[left]] -= 1
            if char_freq[s[left]] == 0:
                del char_freq[s[left]]
            left += 1

        # Update the maximum length of the valid substring
        max_length = max(max_length, right - left + 1)
        right += 1

    return max_length
```

This implementation uses the sliding window pattern to efficiently find the length of the longest substring with at most `k` distinct characters. The `left` and `right` pointers define the current window, and the `char_freq` dictionary keeps track of the frequency of each character in the window. The algorithm expands the window by adding characters to the right, and contracts the window by removing characters from the left, ensuring that the window always contains at most `k` distinct characters.

## 4. Applications and Scenarios

The sliding window pattern is widely used in various problem domains, including:

1. **Substring and Subarray Problems**: Finding the longest/shortest subarray or substring that satisfies a certain condition, such as the maximum sum subarray or the longest palindromic substring.

2. **Frequency-based Problems**: Solving problems that involve finding the maximum/minimum frequency of elements in a subarray or substring, such as the problem of finding the longest substring with at most `k` distinct characters.

3. **Optimization Problems**: Optimizing the use of a fixed-size resource or space, such as finding the minimum window substring that contains all the characters in a target string.

4. **Streaming Data Analysis**: Analyzing data streams or sequences in real-time, such as finding the maximum or minimum value in a sliding window of a data stream.

The sliding window pattern is most effective when the problem can be solved by maintaining a "window" of elements and updating the window as needed. It allows for efficient problem-solving by avoiding unnecessary computations and reducing the search space.

## 5. Practice Problems

Here are some practice problems to reinforce your understanding of the sliding window pattern:

Easy:
1. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
2. [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
3. [Permutation in String](https://leetcode.com/problems/permutation-in-string/)
4. [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
5. [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

Medium:
1. [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
2. [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
3. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
4. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
5. [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

Hard:
1. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
2. [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
3. [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)
4. [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
5. [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
