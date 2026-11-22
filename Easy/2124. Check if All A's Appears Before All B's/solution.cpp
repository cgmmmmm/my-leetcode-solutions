class Solution {
public:
    bool checkString(string s) 
    {
        bool met_b = false;
        for (char ch : s) 
        {
            if (ch == 'a' && met_b)
                return false;
            if (ch == 'b')
                met_b = true;
        }
        return true;
    }
};