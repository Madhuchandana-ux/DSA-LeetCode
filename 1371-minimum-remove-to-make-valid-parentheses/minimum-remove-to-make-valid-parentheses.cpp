
#include <string>
#include <stack>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // Stores indices of unmatched '('
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Matched with a previous '('
                } else {
                    s[i] = '#'; // Unmatched ')', mark for removal
                }
            }
        }
        
        // Any remaining indices in the stack are unmatched '('
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        
        // Build the result string excluding marked '#' characters
        string result = "";
        for (char c : s) {
            if (c != '#') {
                result += c;
            }
        }
        
        return result;
    }
};
