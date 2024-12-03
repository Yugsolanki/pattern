// Longest Subarray of 1's After Deleting One Element
// Given an array of integers, return the length of the longest subarray of 1's after deleting one element.
// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 1's.
// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]    
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] contains 5 1's.
// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
// Example 4:
// Input: nums = [1,1,0,0,1,1,1,0,1]
// Output: 4

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_length = 0;
        int left = 0;
        int zeros = 0;

        for (int right = 0; right < nums.size(); right++) {
            // If we encounter 0, increment the zeros count
            if (nums[right] == 0) {
                zeros++;
            }
            // If zeros count is greater than 1, then we need to move the left pointer
            while (zeros > 1 && left <= right) {
                // If we encounter 0, decrement the zeros count
                // We check is nums[left] == 0, because we need to decrement the zeros count only if we are deleting 0
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            max_length = max(max_length, right - left); // No +1 because we are deleting one element
        }
        return max_length;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

int main() {
    Solution sol;
    vector<int> nums = {1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    nums = {0,1,1,1,0,1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    nums = {1,1,1};
    cout << sol.longestSubarray(nums) << endl;

    nums = {1,1,0,0,1,1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}

// Output
// 3
// 5
// 2
// 4