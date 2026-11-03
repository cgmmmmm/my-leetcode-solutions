class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int mx = *std::max_element(nums.begin(), nums.end());
        int res = 0;
        for (const int& num : nums)
        {
            res += (mx-num);
        }
        return res;
    }
};