class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) 
    {
        std::sort(logs.begin(), logs.end(), [](const auto& l1, const auto& l2)
        {
            return l1[1] < l2[1];
        });

        size_t m = queries.size();
        std::vector<std::pair<int, size_t>> q;
        for (size_t i=0; i<m; ++i)
        {
            q.push_back({queries[i], i});
        }
        std::sort(q.begin(), q.end());
        
        std::vector<int> res(m, n);
        std::vector<int> freq(n+1, 0);
        int total_logs = logs.size();
        size_t l = 0, r = 0;
        int active = 0;
        for (auto& [endTime, idx] : q)
        {
            int startTime = endTime - x;
            while (r < total_logs && endTime >= logs[r][1])
            {
                int id = logs[r][0];
                if (freq[id] == 0) active++;
                freq[id]++;
                r++;
            }

            while (l < total_logs && startTime > logs[l][1])
            {
                int id = logs[l][0];
                freq[id]--;
                if (freq[id] == 0) active--;
                l++;
            }

            res[idx] -= active;
        }

        return res;
    }
};