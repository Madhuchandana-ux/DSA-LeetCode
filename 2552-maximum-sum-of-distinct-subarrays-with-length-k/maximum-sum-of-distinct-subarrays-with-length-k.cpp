class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0;
        long long maxi = 0;
        int l = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            freq[nums[i]]++;

            // When window size exceeds k, shrink from the left
            if (i - l + 1 > k) {
                sum -= nums[l];
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }

            // When window size is exactly k and all elements are distinct
            if (i - l + 1 == k && freq.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};