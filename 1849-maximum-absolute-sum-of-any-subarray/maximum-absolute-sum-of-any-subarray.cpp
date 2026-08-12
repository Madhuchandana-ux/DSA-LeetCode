#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int max_sum = 0, current_max = 0;
        int min_sum = 0, current_min = 0;

        for (int num : nums) {
            // Track maximum subarray sum
            current_max = std::max(num, current_max + num);
            max_sum = std::max(max_sum, current_max);

            // Track minimum subarray sum
            current_min = std::min(num, current_min + num);
            min_sum = std::min(min_sum, current_min);
        }

        return std::max(max_sum, std::abs(min_sum));
    }
};