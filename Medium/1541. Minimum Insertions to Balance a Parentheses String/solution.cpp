class Solution {
public:
    int minInsertions(string s) 
    {
        int cnt = 0;
        std::stack<char> st;

        int n = s.size(), i = 0;
        while (i < n-1)
        {
            if (s[i] == '(')
            {
                st.push('(');
                i++;
            }
            else
            {
                if (st.empty() && s[i+1] != ')')
                {
                    cnt+=2;
                    i++;
                }
                else if (st.empty() && s[i+1] == ')')
                {
                    cnt++;
                    i+=2;
                }
                else if (!st.empty() && s[i+1] != ')')
                {
                    st.pop();
                    cnt++;
                    i++;
                }
                else if (!st.empty() && s[i+1] == ')')
                {
                    st.pop();
                    i+=2;
                } 
            }
        }

        if (i == n-1)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                if (st.empty()) cnt+=2;
                else if (!st.empty())
                {
                    st.pop();
                    cnt++;
                }
            }
        }

        while (!st.empty())
        {
            cnt+=2;
            st.pop();
        }

        return cnt;
    }
};