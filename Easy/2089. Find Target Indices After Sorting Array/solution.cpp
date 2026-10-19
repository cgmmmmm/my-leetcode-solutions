class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        int n = nums.size();
        std::vector<int> res;

        int startIdx = 0;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] < target)
            {
                startIdx++;
            }
        }

        for (int i=0; i<n; ++i)
        {
            if (nums[i] == target)
            {
                res.push_back(startIdx++);
            }
        }

        return res;
    }
};
