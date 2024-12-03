// Intersection of Two Arrays

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                // ans.empty will check if the array is empty or not if the array is empty then it will insert nums[i] because there is nothing to compare with in the .back() part. 
                // and if there is atleast one element in the array then it will compare it the last element of the array and if it not the same then only we will insert.
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++; j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

// Time Complexity: O(mlogm + nlogn)
// Space Complexity: O(1)

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = sol.intersection(nums1, nums2);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// Output: 2