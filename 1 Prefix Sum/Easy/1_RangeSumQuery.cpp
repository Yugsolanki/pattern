// Range Sum Query - Immutable

#include <iostream>
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        if (!nums.empty()) {
            sum_nums.push_back(nums[0]);
            for (size_t i = 1; i < nums.size(); ++i) {
                sum_nums.push_back(sum_nums.back() + nums[i]);
            }
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return sum_nums[right];
        } else {
            return sum_nums[right] - sum_nums[left - 1];
        }
    }

private:
    std::vector<int> sum_nums;
};

// Time Complexity: O(n)
// Space Complexity: O(n)

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);
    std::cout << obj.sumRange(0, 2) << std::endl;
    std::cout << obj.sumRange(2, 5) << std::endl;
    std::cout << obj.sumRange(0, 5) << std::endl;
    return 0;
}

// Output: 1