class Solution {
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (single-character center)
            totalCount += expandAroundCenter(s, i, i);
            
            // Even length palindromes (two-character center)
            totalCount += expandAroundCenter(s, i, i + 1);
        }
        
        return totalCount;
    }
};