class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.size();
        
        if (n == 1) return 0;
        if (n == 2) return (s[0] > s[1]) ? -1 : 0;

        int smIdx = 0, lgIdx = 0;
        char sm = 'z', lg = 'a';
        bool alreadySorted = true;
        char prev = s[0];
        for (int i=0; i<n; ++i)
        {
            char ch = s[i];
            if (ch < sm)
            {
                sm = ch;
                smIdx = i;
            }
            if (ch >= lg)
            {
                lg = ch;
                lgIdx = i;
            }
            if (ch < prev)
            {
                alreadySorted = false;
            }
            prev = ch;
        }

        if (alreadySorted) return 0;
        if (smIdx == 0 || lgIdx == n-1) return 1;
        if (smIdx == n-1 && lgIdx == 0) return 3;

        return 2;
    }
};