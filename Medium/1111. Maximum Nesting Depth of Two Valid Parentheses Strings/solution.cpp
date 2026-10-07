class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int n = seq.size();
        std::vector<int> res(n, 0);

        int max_depth = 0;
        int depth = 0;
        for (int i=0; i<n; ++i)
        {
            if (seq[i] == '(') depth++;
            else depth--;
            max_depth = std::max(max_depth, depth);
        }
        int half_depth = max_depth / 2;

        for (int i=0; i<n; ++i)
        {
            if (seq[i] == '(') 
            {
                depth++;
                if (depth > half_depth) res[i] = 1;
            }
            else
            {
                if (depth > half_depth) res[i] = 1;
                depth--;
            }
        }

        return res;
    }
};