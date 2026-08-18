class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[mid + 1]) {
                // Ascending slope: A peak must exist to the right
                left = mid + 1;
            } else {
                // Descending slope: Mid could be a peak, or a peak exists to the left
                right = mid;
            }
        }
        
        return left; // 'left' and 'right' converge on the peak index
    }
};