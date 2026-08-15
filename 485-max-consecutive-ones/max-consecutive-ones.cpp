class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
                maxi = max(maxi, cnt); // Update maximum consecutive ones seen so far
            } else {
                cnt = 0; // Reset counter when a 0 is encountered
            }
        }

        return maxi;
    }
};