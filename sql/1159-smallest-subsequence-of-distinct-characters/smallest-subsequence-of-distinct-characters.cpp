class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (visited[c - 'a']) continue;

            // Pop elements if they are larger than c and appear again later in s
            while (!result.empty() && result.back() > c && lastIndex[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};