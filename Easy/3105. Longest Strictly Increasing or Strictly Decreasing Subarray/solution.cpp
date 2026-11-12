class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n = nums.size();

        if (n == 1) return 1;

        int inc = 1, dec = 1;
        bool increasing = false, decreasing = false;

        int cnt = 1;
        for (int i=1; i<n; ++i)
        {
            if (nums[i-1] < nums[i])
            {
                if (decreasing)
                {
                    cnt = 1;
                }
                increasing = true;
                decreasing = false;
                
                cnt += 1;
                inc = (inc >= cnt) ? inc : cnt;
            }
            else if (nums[i-1] > nums[i])
            {
                if (increasing)
                {
                    cnt = 1;
                }
                increasing = false;
                decreasing = true;

                cnt += 1;
                dec = (dec >= cnt) ? dec : cnt;
            }
            else
            {
                cnt = 1;
            }
        }

        return (inc > dec) ? inc : dec;
    }
};