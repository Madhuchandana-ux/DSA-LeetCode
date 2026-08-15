class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;
        int maxi = 1;
        
        for (int i = 1; i < s.length(); i++) {
            // Check if current char is the next consecutive alphabet letter
            if (s[i] - s[i - 1] == 1) {
                cnt++;
                maxi = max(maxi, cnt);
            } else {
                cnt = 1; // Reset count to 1 for the current character
            }
        }
        
        return maxi;
    }
};