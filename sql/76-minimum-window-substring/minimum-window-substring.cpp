#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        // Track character counts needed for string t
        vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int required = t.length(); // Total characters we still need to match
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            // If s[right] was needed in t, decrement 'required'
            if (count[s[right]] > 0) {
                required--;
            }
            // Decrement frequency count for s[right]
            count[s[right]]--;
            right++;

            // When all characters are matched, shrink the window from the left
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                // Remove s[left] from the window
                count[s[left]]++;
                // If count becomes > 0, it means we are now missing a character from t
                if (count[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};