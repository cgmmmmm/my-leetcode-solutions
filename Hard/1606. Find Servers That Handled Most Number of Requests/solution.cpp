struct Process {
    int finish_time;
    int server_id;

    bool operator>(const Process& other) const
    {
        if (finish_time == other.finish_time)
        {
            return server_id > other.server_id;
        }
        return finish_time > other.finish_time;
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrivals, vector<int>& loads) 
    {
        int n = arrivals.size();

        if (k == 1 || n == 1) return {0};

        std::vector<int> tallies(k, 0);
        std::set<int> free_servers;
        for (int i=0; i<k; ++i)
        {
            free_servers.insert(i);
        }
        std::priority_queue<Process, 
                            std::vector<Process>, 
                            std::greater<Process>> processes;
        int max_tally = 0;

        for (int i=0; i<n; ++i)
        {
            int arrive_time = arrivals[i];

            if (free_servers.empty() && 
                !processes.empty() && 
                processes.top().finish_time > arrive_time)
                continue;

            while (!processes.empty() && 
                    processes.top().finish_time <= arrive_time)
            {
                free_servers.insert(processes.top().server_id);
                processes.pop();
            }

            int target_id = i % k;
            auto it = free_servers.lower_bound(target_id);
            if (it == free_servers.end())
            {
                it = free_servers.begin();
            }
            target_id = *it;

            processes.push({arrive_time + loads[i], target_id});
            free_servers.erase(it);

            int count = ++tallies[target_id];
            max_tally = (count > max_tally) ? count : max_tally;
        }

        std::vector<int> res;
        for (int i=0; i<k; ++i)
        {
            if (tallies[i] == max_tally) res.push_back(i);
        }

        return res;
    }
};