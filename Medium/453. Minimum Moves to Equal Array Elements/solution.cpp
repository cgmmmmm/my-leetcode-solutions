class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int min_val = *std::min_element(nums.begin(), nums.end());
        
        int res = 0;
        for (int num : nums)
        {
            if (num == min_val) continue;

            res += (num - min_val);
        }

        return res;
    }
};