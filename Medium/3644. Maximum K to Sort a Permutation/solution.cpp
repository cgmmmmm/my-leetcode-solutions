class Solution {
public:
    int sortPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int res = INT_MAX;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] != i)
            {
                res &= nums[i];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};