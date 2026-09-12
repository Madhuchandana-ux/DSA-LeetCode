class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0;
        int cnt = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            
            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++; // Increment left pointer
            }
            
            cnt += (right - left + 1);
        }
        
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};