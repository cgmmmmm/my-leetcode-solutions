class Solution {
public:
    std::string digitSum(std::string s, int k) 
    {
        while (s.size() > k)
        {
            std::string tmp;
            int sum = 0;
            int l = 0, r = 0;
            while (r < s.size())
            {
                sum = 0;
                while (r < s.size() && r-l+1 <= k)
                {
                    sum += s[r] - '0';
                    r++;
                }

                if (r >= s.size()) break;
            
                tmp += std::to_string(sum);

                l = r;
            }
            if (l < s.size()) tmp += std::to_string(sum);

            s = tmp;
        }

        return s;
    }
};