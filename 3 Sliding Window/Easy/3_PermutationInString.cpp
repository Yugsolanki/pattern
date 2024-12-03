// Permutation In String
// Given two strings s1 and s2, return true if s2 contains the permutation of s1.
// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo
// Output: false

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1map;
        for (auto ch: s1) {
            s1map[ch] += 1;
        }

        int m = s1.size();
        int n = s2.size();

        if (m>n) return false;

        // Reason for n-m is that we need to check the window of size m in s2
        // So, we need to iterate only till n-m
        // Otherwise, we will get out of bound error, because i + j  should be less than n
        for (int i = 0; i <= n-m; i++) {
            unordered_map<char, int> s2map;

            // j < m ensures that we are checking the window of size as same as of s1
            // insert the elements of s2 in the map only len(s1) elements
            // i + j is becuase i is the starting index of the window
            // j iterates over the window to insert element
            for (int j = 0; j < m; j++) {
                s2map[s2[i+j]]++;
            }
            
            if (s1map == s2map) {
                return true;
            }
        }
        return false;
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(1)

int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << sol.checkInclusion(s1, s2) << endl;
    return 0;
}

// Output: True