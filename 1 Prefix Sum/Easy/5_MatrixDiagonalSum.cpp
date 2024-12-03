// Matrix Diagonal Sum

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Method 1: Brute Force
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int pri = 0, sec = 0;
        int m = mat.size(), n = mat[0].size();

        for (int i = 0, j = n-1; i < m && j < m; i++, j--) {
            if (i == j) {
                pri += mat[i][i];
            } else {
                pri += mat[i][i];
                sec += mat[i][j];
            }
        }
        return pri+sec;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)


// Method 2: Optimized
class Solution2 {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();  // size of the square matrix
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            // Primary diagonal: mat[i][i]
            sum += mat[i][i];

            // Secondary diagonal: mat[i][n - 1 - i]. 
            // If i == n - 1 - i, it means we are at the middle element of the matrix.
            if (i != n - 1 - i) {  // Avoid double-counting the middle element for odd-sized matrices
                sum += mat[i][n - 1 - i];
            }
        }

        return sum;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

void main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution2 solution;
    int diagonalSum = solution.diagonalSum(mat);
    cout << diagonalSum;
}

// Output: 25