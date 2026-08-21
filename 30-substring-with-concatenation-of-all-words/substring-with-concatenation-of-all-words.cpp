#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int s_len = s.length();
        
        unordered_map<string, int> word_counts;
        for (const string& word : words) {
            word_counts[word]++;
        }

        // Loop over all possible word offsets
        for (int i = 0; i < word_len; ++i) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen_words;

            for (int right = i; right + word_len <= s_len; right += word_len) {
                string sub = s.substr(right, word_len);

                if (word_counts.count(sub)) {
                    seen_words[sub]++;
                    count++;

                    // If a word frequency exceeds allowed count, shrink window from left
                    while (seen_words[sub] > word_counts[sub]) {
                        string left_word = s.substr(left, word_len);
                        seen_words[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // If window contains all target words
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window if an unknown word is encountered
                    seen_words.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};