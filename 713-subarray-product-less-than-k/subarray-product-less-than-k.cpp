class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //2Edge.case:0and1N/A because.array.elements >= 1
        if (k <= 1) return 0;

        int product = 1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            //.Shrink1window.from.left.until.product.is < k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            //2All.subarrays.ending.at 'right' from.index 'left' to 'right'
            count += right - left + 1;
        }

        return count;
    }
};