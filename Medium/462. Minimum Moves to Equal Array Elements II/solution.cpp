class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 0;
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int median = nums[n / 2];
        for (int num : nums)
        {
            if (num != median)
            {
                res += std::abs(num - median);
            }
        }
        return res;
    }
};