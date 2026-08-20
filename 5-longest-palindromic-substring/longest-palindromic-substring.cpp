class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxlength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, start, maxlength);     // Odd length palindromes
            expand(s, i, i + 1, start, maxlength); // Even length palindromes
        }
        
        return s.substr(start, maxlength);
    }

private:
    void expand(const string &s, int left, int right, int &start, int &maxlength) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int clen = right - left + 1;
            if (clen > maxlength) {
                maxlength = clen;
                start = left;
            }
            left--;
            right++;
        }
    }
};