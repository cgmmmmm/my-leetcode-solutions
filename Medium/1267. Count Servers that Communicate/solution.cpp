class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    // up
                    int up = i-1;
                    while (up >= 0 && !visited[up][j])
                    {
                        if (grid[up][j] == 1)
                        {
                            visited[up][j] = true;
                            res++;
                        }
                        up--;
                    }
                    // right
                    int right = j+1;
                    while (right < n && !visited[i][right])
                    {
                        if (grid[i][right] == 1)
                        {
                            visited[i][right] = true;
                            res++;
                        }
                        right++;
                    }
                    //down 
                    int down = i+1;
                    while (down < m && !visited[down][j])
                    {
                        if (grid[down][j] == 1)
                        {
                            visited[down][j] = true;
                            res++;
                        }
                        down++;
                    }
                    // left
                    int left = j-1;
                    while(left >= 0 && !visited[i][left])
                    {
                        if (grid[i][left] == 1)
                        {
                            visited[i][left] = true;
                            res++;
                        }
                        left--;
                    }
                }
            }
        }

        return res;
    }
};