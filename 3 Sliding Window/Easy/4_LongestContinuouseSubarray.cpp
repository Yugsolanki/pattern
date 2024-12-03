// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
// Example 1:
// Input: nums = [8,2,4,7], limit = 4
// Output: 2
// Explanation: All subarrays are:
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.
// Example 2:
// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:
// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

class Solution {
public:
    int longestContinuouseSubarray(vector<int>& nums, int limit) {
        int max_length = 0;
        int left = 0, right = 0;

        while (left < nums.size()) {
            int min_sub = INT_MAX, max_sub = 0;
            right = left;
            while (right <= nums.size()) {
                min_sub = min(min_sub, nums[right]);
                max_sub = max(max_sub, nums[right]);
                int dif = max_sub - min_sub;
                if (dif <= limit) {
                    max_length = max(max_length, right - left + 1);
                }
                if (right == nums.size() - 1) {
                    break;
                }
                right++;
            }
            left++;
        }
        return max_length;
    }
};


class Solution1 {
public:
    int longestContinuousSubarray(vector<int>& nums, int limit) {
        int max_length = 0;
        int left = 0, right = 0;

        deque<int> minDeque, maxDeque;
        
        while (right < nums.size()) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
        }
    }
}


// Approach: Sliding Window




// Time Complexity: O(n^2)
// Space Complexity: O(1)

int main() {
    Solution sol;
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    cout << sol.longestContinuouseSubarray(nums, limit) << endl;

    vector<int> nums1 = {10,1,2,4,7,2};
    int limit1 = 5;
    cout << sol.longestContinuouseSubarray(nums1, limit1) << endl;

    vector<int> nums2 = {4,2,2,2,4,4,2,2};
    int limit2 = 0;
    cout << sol.longestContinuouseSubarray(nums2, limit2) << endl;
    return 0;
}