#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) { return false; }

        std::stack<char> st;

        for (char c : s) {
            if (c == ')')
            {
                if (st.empty() || (!st.empty() && st.top() != '('))
                    return false;
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || (!st.empty() && st.top() != '['))
                    return false;
                st.pop();
            }
            else if (c == '}')
            {
                if (st.empty() || (!st.empty() && st.top() != '{'))
                    return false;
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};