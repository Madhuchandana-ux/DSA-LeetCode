class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case: prefix sum of 0 appears once
        
        int current_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            // If (current_sum - k) exists in map, add its frequency to count
            if (mp.find(current_sum - k) != mp.end()) {
                count += mp[current_sum - k];
            }
            
            // Record/update current prefix sum frequency
            mp[current_sum]++;
        }
        
        return count;
    }
};