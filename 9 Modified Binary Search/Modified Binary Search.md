# Modified Binary Search Pattern

## 1. Concise Explanation and Purpose

The modified binary search pattern is a variation of the classic binary search algorithm used to find an element in a sorted array. The key difference is that the modified version allows for searching in a rotated sorted array, where the array has been circularly shifted by an unknown amount.

The purpose of this pattern is to handle cases where the input array is not strictly monotonically increasing, but rather has been rotated around some unknown pivot point. This can occur in scenarios like searching for an item in a sorted array that has been shifted due to updates or insertions.

## 2. Detailed Walkthrough

The modified binary search pattern follows these steps:

1. **Initialize left and right pointers**: Set the `left` pointer to the first index of the array (0) and the `right` pointer to the last index of the array (`arr.length - 1`).

2. **Check if the array is sorted**: Compare the element at the `left` pointer to the element at the `right` pointer. If `arr[left] < arr[right]`, the array is sorted, and we can proceed with a standard binary search.

3. **Find the pivot point**: If the array is not sorted, we need to find the pivot point where the array was rotated. To do this, we can compare the middle element (`arr[mid]`) to the first (`arr[left]`) and last (`arr[right]`) elements:
   - If `arr[mid] >= arr[left]`, the left half of the array is sorted, so the pivot point is in the right half. Update `left = mid + 1`.
   - If `arr[mid] < arr[left]`, the right half of the array is sorted, so the pivot point is in the left half. Update `right = mid`.

4. **Perform binary search**: Once we've identified the pivot point, we can perform a standard binary search in the correct half of the array. Depending on the target value, we'll either search the left or right half:
   - If the target is less than the first element (`arr[left]`), search the right half by setting `left = mid + 1`.
   - If the target is greater than or equal to the first element (`arr[left]`), search the left half by setting `right = mid - 1`.

5. **Return the index**: If the target is found, return the index. If the target is not found, return -1.

Here's a step-by-step walkthrough with an example:

```
Input array: [4, 5, 6, 7, 0, 1, 2]
Target: 0

1. Initialize: left = 0, right = 6
2. Check if sorted: arr[0] = 4 < arr[6] = 2, so the array is not sorted.
3. Find pivot point:
   - mid = (0 + 6) // 2 = 3
   - arr[mid] = 7 >= arr[0] = 4, so the pivot is in the right half
   - Update left = mid + 1 = 4
4. Perform binary search on right half:
   - mid = (4 + 6) // 2 = 5
   - arr[mid] = 1 < target = 0, so the target is in the left half
   - Update right = mid - 1 = 4
   - mid = (4 + 4) // 2 = 4
   - arr[mid] = 0 == target = 0, so the target is found
5. Return the index: 4
```

## 3. Code Implementation

Here's an implementation of the modified binary search pattern in Python:

```python
def search_in_rotated_sorted_array(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid

        # If the left half is sorted
        if arr[left] <= arr[mid]:
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        # If the right half is sorted
        else:
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1
```

## 4. Applications and Scenarios

**Applications:**
- Searching for an element in a sorted array that has been rotated by an unknown amount.
- Identifying the pivot point where a sorted array has been shifted.
- Solving problems that involve finding a target value in a partially sorted data structure.

**Scenarios:**
- Searching for a product in an e-commerce catalog that has been reorganized.
- Finding a specific file in a directory structure that has been rearranged.
- Identifying a target value in a sorted array that has been circularly shifted due to updates or insertions.

## 5. Practice Problems

### Easy
1. [LeetCode 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
2. [LeetCode 81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
3. [LeetCode 153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
4. [LeetCode 154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
5. [GeeksforGeeks: Search an element in a sorted and pivoted array](https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/)

### Medium
1. [LeetCode 278. First Bad Version](https://leetcode.com/problems/first-bad-version/)
2. [LeetCode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
3. [LeetCode 702. Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/)
4. [LeetCode 852. Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
5. [LeetCode 1095. Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

### Difficult
1. [LeetCode 420. Strong Password Checker](https://leetcode.com/problems/strong-password-checker/)
2. [LeetCode 668. Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)
3. [LeetCode 719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
4. [LeetCode 787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
5. [LeetCode 1231. Divide Chocolate](https://leetcode.com/problems/divide-chocolate/)