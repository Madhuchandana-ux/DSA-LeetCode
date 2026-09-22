#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            // Treat the element past the end as height 0 to flush remaining elements from the stack
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                // If stack is empty, the rectangle spans from index 0 to i - 1
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = std::max(maxArea, h * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};