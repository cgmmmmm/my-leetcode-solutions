class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) 
    {
        int n = gs.size();
        std::unordered_map<int, std::vector<int>> mp;
        for (int i=0; i<n; ++i)
        {
            mp[gs[i]].push_back(i);
        }

        std::vector<std::vector<int>> res;
        for (auto& [sz, people] : mp)
        {
            std::vector<int> currGrp;
            for (int person : people)
            {
                currGrp.push_back(person);
                if (currGrp.size() == sz)
                {
                    res.push_back(std::move(currGrp));
                    currGrp.clear();
                }
            }
        }

        return res;
    }
};