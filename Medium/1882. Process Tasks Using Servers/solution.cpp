using uint = unsigned int;

class Solution {
public:
    vector<int> assignTasks(vector<int>& svrs, vector<int>& tasks) 
    {
        int n = svrs.size();
        int m = tasks.size();
        
        std::multiset<std::pair<int, int>> servers;
        for (int i=0; i<n; ++i)
        {
            servers.emplace(svrs[i], i);
        }

        std::vector<int> res;
        res.reserve(m);
        
        uint time = 0;
        int i = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<uint, int>>> q;
        while (i < m)
        {
            time = (time > i) ? time : i;

            if (servers.empty())
            {
                time = q.top().first;
            }

            // free server
            while (!q.empty() && q.top().first <= time)
            {
                const auto& [finish_time, id] = q.top();
                servers.emplace(svrs[id], id);
                q.pop();
            }

            // assign appropriate server to task
            auto it = servers.begin();
            q.emplace(time + tasks[i], it->second);
            res.push_back(it->second);
            servers.erase(it);
            i++;
        }

        return res;
    }
};

/**
Eg1:
servers = [{2,2}, {3,0}, {3,1}]

Time 0:
i = 0
q = [{1,2}]
res = [2]
servers = [{3,0}, {3,1}]

Time 1:
i = 1
q = [{3,2}]
res = [2,2]
servers = [{3,0}, {3,1}]

Time 2:
i = 2
q = [{3,2}, {5,0}]
res = [2,2,0]
servers = [{3,1}]

Time 3:
i = 3
q = [{5,0}, {5,2}]
res = [2,2,0,2]
servers = [{3,1}]

Time 4:
i = 4
q = [{5,0}, {5,2}, {5,1}]
res = [2,2,0,2,1]
servers = []

Time 5:
i = 5
q = [{7,2}]
res = [2,2,0,2,1,2]
servers = [{3,0}, {3,1}]

*/

/**
1. use multiset<pair<int, int>> to store servers of {weight, id}, ascending order.
2. use min_heap to track processes {finish_time, id} in queue, ordered by finish_time.
*/