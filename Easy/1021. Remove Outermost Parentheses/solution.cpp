class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        std::string res;
        int depth = 0;

        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '(')
            {
                if (depth > 0) res.push_back('(');
                depth++;
            }
            else
            {
                depth--;
                if (depth > 0) res.push_back(')');
            }
        }

        return res;
    }
};