class Solution {
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) 
    {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        int validStringLength = -1;

        q.push(s);
        visited.insert(s);
        while (!q.empty())
        {
            std::string curr = q.front();
            q.pop();

            int len = curr.size();

            if (len < validStringLength)    
                continue;

            if (isValidParentheses(curr))
            {
                validStringLength = len;
                res.push_back(curr);
            }

            if (validStringLength == -1)
            {
                for (int i=0; i<len; ++i)
                {
                    if (curr[i] != '(' && curr[i] != ')') continue;
                    std::string str = curr.substr(0, i) + curr.substr(i + 1);
                    if (!visited.count(str))
                    {
                        q.push(str);
                        visited.insert(str);
                    }
                }
            }
        }

        return (res.empty()) ? std::vector<std::string>{""} : res;
    }

    bool isValidParentheses(const std::string& s)
    {
        int counter = 0;
        for (char c : s)
        {
            if (c == '(') counter++;
            else if (c == ')')
            {
                counter--;
                if (counter < 0) return false;
            }
        }
        return (counter == 0);
    }
};