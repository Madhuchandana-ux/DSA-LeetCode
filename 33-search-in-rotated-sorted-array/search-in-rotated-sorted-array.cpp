class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid; // Found target
            }

            // Check if left half is sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target in left half
                } else {
                    l = mid + 1; // Target in right half
                }
            }
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target in right half
                } else {
                    r = mid - 1; // Target in left half
                }
            }
        }

        return -1; // Target not found
    }
};