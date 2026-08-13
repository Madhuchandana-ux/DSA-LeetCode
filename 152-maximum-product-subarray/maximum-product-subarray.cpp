class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];   // maximum product ending at current index
        int currMin = nums[0];   // minimum product ending at current index
        int ans = nums[0];       // global maximum product

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(currMax, currMin); // flip when negative

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }
        return ans;
    }
};