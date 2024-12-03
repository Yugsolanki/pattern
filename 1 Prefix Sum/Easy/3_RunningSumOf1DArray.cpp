// Running Sum of 1d Array

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum;
        runningSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            runningSum.push_back(runningSum[runningSum.size()-1] + nums[i]);
        }
        return runningSum;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

void main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    vector<int> runningSum = solution.runningSum(nums);
    for (int i = 0; i < runningSum.size(); i++) {
        cout << runningSum[i] << " ";
    }
}

// Output: 1 3 6 10