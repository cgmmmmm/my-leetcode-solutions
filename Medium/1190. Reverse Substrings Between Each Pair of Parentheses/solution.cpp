class Solution {
public:
    std::string helper(std::string_view sv, size_t& i, const size_t n)
    {
        std::string ss;
        while (i < n)
        {
            if (sv[i] == '(')
            {
                size_t start = i++;
                int depth = 1;
                while (i < n && depth > 0)
                {
                    if (sv[i] == '(') depth++;
                    else if (sv[i] == ')') depth--;
                    i++;
                }

                size_t sub_i = 0;
                std::string sub_str = helper(sv.substr(start+1, i-start-2), sub_i, i-start-2);

                ss.append(sub_str);
            }
            else
            {
                ss.push_back(sv[i]);
                i++;
            }
        }

        std::reverse(ss.begin(), ss.end());

        return ss;
    }

    string reverseParentheses(string s) 
    {
        size_t sub_i = 0;
        std::string res = helper(std::string_view(s), sub_i, s.size());
        std::reverse(res.begin(), res.end());
        return res;
    }
};