using ull = unsigned long long;

class Solution {
public:
    int maxLength(vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0;
        for (int l = 0; l < n; ++l) 
        {
            ull product = nums[l];
            ull current_gcd = nums[l];
            ull current_lcm = nums[l];

            for (int r = l + 1; r < n; ++r) 
            {
                product *= nums[r];
                current_gcd = std::gcd(current_gcd, (ull)nums[r]);
                current_lcm = std::lcm(current_lcm, (ull)nums[r]);

                if (product == current_gcd * current_lcm) 
                {
                    res = std::max(res, r-l+1);
                }
            }
        }

        return res;
    }
};