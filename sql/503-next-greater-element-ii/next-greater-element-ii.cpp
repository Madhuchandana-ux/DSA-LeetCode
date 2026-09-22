class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result array with -1
        stack<int> s;

        // Loop from (2*n - 1) down to 0 to simulate circular traversal
        for (int i = 2 * n - 1; i >= 0; --i) {
            int curr = nums[i % n];

            // 1. Maintain Monotonic Stack:
            // Remove all elements smaller than or equal to current element
            while (!s.empty() && s.top() <= curr) {
                s.pop();
            }

            // 2. Assign Result (First Pass Only):
            // If the stack isn't empty, s.top() is the next greater element
            if (i < n && !s.empty()) {
                result[i] = s.top();
            }

            // 3. Push current element for preceding elements to use
            s.push(curr);
        }

        return result;
    }
};