class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        // Edge case: if p is longer than s, an anagram is impossible
        if (m > n) return {};

        vector<int> pc(26, 0);
        vector<int> sc(26, 0);
        vector<int> res;

        for (int i = 0; i < m; i++) {
            pc[p[i] - 'a']++;
            sc[s[i] - 'a']++;
        }

        if (pc == sc) {
            res.push_back(0);
        }

        for (int i = m; i < n; i++) {
            sc[s[i] - 'a']++;
            sc[s[i - m] - 'a']--; // Note: fixed index parenthesis for clarity

            if (pc == sc) {
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};