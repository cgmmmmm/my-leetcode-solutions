class Solution {
public:
    int scoreOfParentheses(string s) {
        std::stack<int> st;
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(0);
            }
            else
            {
                if (!st.empty() && st.top() > 0)
                {
                    int sum = 0;
                    while (!st.empty() && st.top() > 0)
                    {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    sum *= 2;
                    st.push(sum);
                }
                else if (!st.empty() && st.top() == 0)
                {
                    st.pop();
                    st.push(1);
                }
            }
        }

        int score = 0;
        while (!st.empty())
        {
            score += st.top();
            st.pop();
        }
        
        return score;
    }
};