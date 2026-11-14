class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int mn, int mx) 
    {
        int n = nums.size();
        for (int i=1; i<n; ++i)
        {
            nums[i] += nums[i-1];
        }

        int res = nums[mn-1];
        int l = 0;
        for (int r=0; r<n; ++r)
        {
            if (r-l+1 < mn) continue;

            while (r-l+1 > mx)
            {
                l++;
            }

            int i = l;
            while (r-i+1 >= mn)
            {
                int sum = nums[r];
                if (i > 0) sum -= nums[i-1];

                if (res <= 0 && sum > 0)
                    res = sum;
                else if (res > 0 && sum > 0)
                    res = (res > sum) ? sum : res;

                i++;
            }
        }

        if (res <= 0) return -1;

        return res;
    }
};

/**
when l = 0, the sum of a l..r subarray is the value at index r
when l > 0, the sum of a l..r subarray is ps[r] - ps[l-1]

e.g1:
ps = [3, 1, 2, 6]

*/