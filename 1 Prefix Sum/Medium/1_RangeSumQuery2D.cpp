// Range Sum Query 2D - Immutable

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            prefix.push_back(vector<int>{matrix[i][0]});
            for (int j = 1; j < matrix[0].size(); j++) {
                prefix[i].push_back(prefix[i][prefix[i].size()-1] + matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) {
                sum += prefix[i][col2];
            } else {
                sum += ( prefix[i][col2] - prefix[i][col1 - 1] );
            } 
        }
        return sum;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
    return 0;
}

// Output: 8 11 12