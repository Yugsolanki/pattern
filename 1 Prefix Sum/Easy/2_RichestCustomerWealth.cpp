// Richest Customer Wealth

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> amount;
        int max_amount = 0;
        for (int i = 0; i < accounts.size(); i++) {
            amount.push_back(0);
            for (int j = 0; j < accounts[0].size(); j++) {
                amount[i] += accounts[i][j];
            }

            if (amount[i] > max_amount) {
                max_amount = amount[i];
            }
        }
        return max_amount;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n)

void main() {
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    Solution solution;
    cout << solution.maximumWealth(accounts) << endl;
}

// Output: 6