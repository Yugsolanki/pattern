// Remove Duplicate from Sorted Array 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            // If the left and right pointers are pointing to the same element, we will move the right pointer to the next element.
            // If the left and right pointers are pointing to different elements, we will move the left pointer to the next element and replace the element at the left pointer with the element at the right pointer.
            if (nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates(nums) << endl;
    for (int n : nums) cout << n << " ";
    cout << endl;
    return 0;
}