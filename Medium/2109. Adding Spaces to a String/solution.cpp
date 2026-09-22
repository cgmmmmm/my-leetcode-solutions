class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int l1 = s.size();
        int l2 = spaces.size();
    
        std::string res = "";
        res.reserve(l1 + l2);
        int idx = 0;
        for (int i=0; i<l1; ++i)
        {
            if (idx < l2 && i == spaces[idx])
            {
                res.push_back(' ');
                idx++;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};