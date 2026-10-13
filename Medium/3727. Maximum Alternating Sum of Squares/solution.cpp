class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i=0; i<n; ++i)
        {
            nums[i] *= nums[i];
        }

        int half = n/2;
        long long addSum = 0;
        long long minusSum = 0;
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i)
        {
            if (i < half)
            {
                minusSum += nums[i];
            }
            else
            {
                addSum += nums[i];
            }
        }

        return addSum - minusSum;
    }
};