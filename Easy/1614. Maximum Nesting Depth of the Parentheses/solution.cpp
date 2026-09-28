class Solution {
public:
    int maxDepth(string s) 
    {
        int n = s.size();
        int depth = 0, max_depth = 0;
        for (int i=0; i<n; ++i)
        {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            max_depth = std::max(max_depth, depth);
        }
        return max_depth;
    }
};