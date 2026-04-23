class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        std::unordered_map<long long, std::vector<int>> groups;
        int n = nums.size();

        for (int i=0; i<n; ++i) 
        {
            groups[nums[i]].push_back(i);
        }

        std::vector<long long> res(n, 0);
        for (const auto& pair : groups) 
        {
            const auto& vector = pair.second;
            long long total = 0;
            for (auto it = vector.begin(); it != vector.end(); ++it)
            {
                total += *it;
            }
            long long ps = 0;
            for (int i = 0; i < vector.size(); ++i)
            {
                res[vector[i]] = total - ps * 2 + vector[i] * (2 * i - vector.size());
                ps += vector[i];
            }
        }

        return res;
    }
};
