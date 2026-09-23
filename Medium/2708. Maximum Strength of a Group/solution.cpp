using ll = long long;

class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1 && nums[0] < 0) return nums[0];

        std::sort(nums.begin(), nums.end());

        bool ec = true;
        ll res = 1;
        int idx = 0;
        int negCnt = 0;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] < 0)
            {
                negCnt++;
                if (negCnt % 2 == 0)
                {
                    ec = false;
                    res *= nums[idx++];
                    res *= nums[idx++];
                }
            }
            else if (nums[i] > 0)
            {
                ec = false;
                res *= nums[i];
            }
        }

        return (ec) ? 0 : res;
    }
};