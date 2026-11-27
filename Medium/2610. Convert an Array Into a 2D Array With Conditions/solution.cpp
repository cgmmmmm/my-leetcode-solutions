class Solution {
public:
    std::vector<std::vector<int>> findMatrix(vector<int>& nums) 
    {
        std::vector<int> freq(201, 0);

        int max_freq = 0;
        for (int num : nums)
            max_freq = std::max(++freq[num], max_freq);

        std::vector<std::vector<int>> res(max_freq);

        for (int i=1; i<201; ++i)
        {
            if (freq[i] == 0) continue;
            for (int idx = 0; idx < freq[i]; ++idx) 
                res[idx].push_back(i);
        }

        return res;
    }
};