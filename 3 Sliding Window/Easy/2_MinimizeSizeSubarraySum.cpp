// Minimize Size Subarray Sum
// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// Example:
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Method 1: Using Prefix Sum and Sliding Windows
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix.push_back(nums[i]);
            } else {
                prefix.push_back(prefix[i - 1] + nums[i]);
            }
        }

        int min_len = INT_MAX;
        int sum = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            sum = getSum(prefix, i, j);
            if (sum < target) {
                j++;
            } else {
                min_len = min(min_len, j - i + 1);
                i++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }

    int getSum(vector<int>& prefix, int i, int j) {
        if (i == 0) {
            return prefix[j];
        } else {
            return prefix[j] - prefix[i - 1];
        }
    }
};


// Method 2: Using Just Sliding Windows
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // Edge Case
        if (n == 0) {
            return 0;
        }

        int min_len = INT_MAX;
        int sum = 0;
        int i = 0, j = 0;

        while (j < n) {
            sum += nums[j];
            // If sum is greater than target, then we need to shrink the window from left 
            while (sum >= target) {
                min_len = min(min_len, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int s = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    cout << sol.minSubArrayLen(s, nums) << endl;

    int s1 = 11;
    vector<int> nums1 = {1,1,1,1,1,1,1,1};
    cout << sol.minSubArrayLen(s1, nums1) << endl;
    return 0;
}

// Output: 2