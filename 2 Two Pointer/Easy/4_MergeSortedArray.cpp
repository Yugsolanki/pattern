// Merge Sorted Array 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        // The reason we are starting from behind is because, starting from the start will cause us to shift any element if we need to insert any element from nums2.
        // So, we will start from the end and insert the elements from the end. So it will never cause us to shift any element. 

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

// Time Complexity: O(m + n)
// Space Complexity: O(1)

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution().merge(nums1, 3, nums2, 3);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Output: 1 2 2 3 5 6