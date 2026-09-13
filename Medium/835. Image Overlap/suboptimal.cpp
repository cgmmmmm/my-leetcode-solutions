class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int n=img1.size();
        
        std::vector<std::pair<int, int>> coord1;
        std::vector<std::pair<int, int>> coord2;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (img1[i][j])
                    coord1.push_back({i, j});
                if (img2[i][j])
                    coord2.push_back({i, j});
            }
        }

        std::map<std::pair<int, int>, int> dists;
        int max_overlap = 0;
        for (auto& p1 : coord1)
        {
            for (auto& p2 : coord2)
            {
                int distX = p1.first - p2.first;
                int distY = p1.second - p2.second;
                dists[{distX, distY}]++;

                max_overlap = std::max(max_overlap, dists[{distX, distY}]);
            }
        }
        
        return max_overlap;
    }
};
