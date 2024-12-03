// Find Pivot Index

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        prefix.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix[prefix.size() - 1] + nums[i]);
        }

        int totalSum = prefix[prefix.size() - 1];
        
        for (int i = 0; i < prefix.size(); i++) {
            int leftSum = i == 0 ? 0 : prefix[i-1];
            int rightSum = totalSum - prefix[i];

            if (leftSum == rightSum) {
                return i;
            } else {
                continue;
            }
        }
        return -1;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

void main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution solution;
    int pivotIndex = solution.pivotIndex(nums);
    cout << pivotIndex;
}

// Output: 3