class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long long low = 1, high = x;
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (mid * mid <= x) {
                ans = mid;
                low = mid + 1; // Try to find a larger square root
            } else {
                high = mid - 1; // Target is smaller
            }
        }
        
        return ans;
    }
};