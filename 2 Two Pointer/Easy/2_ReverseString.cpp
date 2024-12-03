// Reverse String

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++; right--;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    for (char c : s) cout << c << " ";
    cout << endl;
    return 0;
}

// Output: o l l e h