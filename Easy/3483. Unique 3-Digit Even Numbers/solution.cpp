class Solution {
public:
    int totalNumbers(vector<int>& digits) 
    {
        std::vector<bool> bitset(900, false);
        int n = digits.size();
        int res = 0;
        for (int i=0; i<n; ++i)
        {
            if (digits[i]==0) continue;
            int a = digits[i] * 100;
            for (int j=0; j<n; ++j)
            {
                if (j==i) continue;
                int b = digits[j] * 10;
                for (int k=0; k<n; ++k)
                {
                    if (k==i || k==j) continue;
                    int num = a + b + digits[k];
                    if (num % 2 == 0) 
                    {
                        if (bitset[num-100] == false) res++;
                        bitset[num-100] = true;
                    }
                }
            }
        }
        return res;
    }
};