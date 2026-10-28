class Solution {
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<std::unordered_set<int>>> memo(m, std::vector<std::unordered_set<int>>(n));

        memo[0][0].insert(grid[0][0]);

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (i == 0 && j == 0) continue;

                if (i - 1 >= 0)
                {
                    for (int x : memo[i-1][j])
                    {
                        memo[i][j].insert(x ^ grid[i][j]);
                    }
                }
                if (j - 1 >= 0)
                {
                    for (int x : memo[i][j-1])
                    {
                        memo[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }

        int res = grid[0][0];
        for (int num=0; num<=1023; ++num)
        {
            if (memo[m-1][n-1].count(num))
            {
                res = num;
                break;
            }
        }

        return res;
    }
};