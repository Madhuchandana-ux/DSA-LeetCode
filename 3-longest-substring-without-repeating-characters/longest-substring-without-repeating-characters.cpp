class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.size()) {
            if (window.find(s[right]) == window.end()) {
                // Add new character
                window.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                // Remove leftmost character until duplicate is gone
                window.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};