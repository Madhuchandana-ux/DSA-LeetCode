#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; ++i) {
            // Reset running product to 1 if it becomes 0
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            maxProd = max({maxProd, prefix, suffix});
        }

        return maxProd;
    }
};