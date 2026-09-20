#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate total hours required at speed 'mid'
            long long totalHours = 0;
            for (int pile : piles) {
                // Ceiling division: (pile + mid - 1) / mid
                totalHours += (pile + mid - 1LL) / mid;
            }

            if (totalHours <= h) {
                ans = mid;         // 'mid' works, try finding a smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;     // 'mid' is too slow, increase speed
            }
        }

        return ans;
    }
};