// Logest Substring Without Repeating Characters
// Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> charfq;
            int max_length = 0;
            int left = 0, right = 0;

            while (right < s.size()) {
                // Add the character to the map, whether it is repeated or not.
                charfq[s[right]] += 1;

                // If the character is repeated, move the left pointer to the right until the character is not repeated
                while (charfq[s[right]] > 1) {
                    charfq[s[left]] -= 1;
                    left++;
                }

                max_length = max(max_length, right - left + 1);
                right++;
            }
            return max_length;
        }
};

// In the following solution we are using the erase function of the unordered_map to remove the character from the map
class Solution2 {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> charfq;
            int max_length = 0;
            int left = 0, right = 0;

            while (right < s.size() && left < s.size()) {
                // If the character is not in the map, add it to the map and move the right pointer to the right
                if (charfq.find(s[right]) == charfq.end()) {
                    charfq[s[right]] = 1;
                    max_length = max(max_length, right - left + 1);
                    right++;
                } else {
                    // If the character is repeated, remove the character from the map and move the left pointer to the right
                    charfq.erase(s[left]);
                    left++;
                }
            }
            return max_length;
        }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

// Output: 3