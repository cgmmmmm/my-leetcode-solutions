class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        std::vector<int> res(k, 0);

        std::sort(logs.begin(), logs.end());

        int prev_id = logs[0][0], prev_time = logs[0][1];
        int uam = 1;
        for (auto& log : logs)
        {
            int id = log[0], time = log[1];

            if (id == prev_id && time == prev_time) 
                continue;
            else if (id == prev_id && time != prev_time)
                uam += 1;
            else if (id != prev_id)
            {
                res[uam-1] += 1;
                uam = 1;
            }
            
            prev_id = id, prev_time = time;
        }
        res[uam-1] += 1;

        return res;
    }
};