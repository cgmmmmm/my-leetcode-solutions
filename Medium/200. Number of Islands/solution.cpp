struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        std::queue<Cell> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        int res = 0;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty())
                    {
                        Cell curr = q.front();
                        q.pop();

                        int x = curr.row, y = curr.col;

                        for (int d=0; d<4; ++d)
                        {
                            int ar = x + dr[d], ac = y + dc[d];

                            if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                            {
                                if (!visited[ar][ac] && grid[ar][ac] == '1')
                                {
                                    q.push({ar, ac});
                                    visited[ar][ac] = true;
                                }
                            }
                        }
                    }

                    res++;
                }
            }
        }

        return res;
    }
};