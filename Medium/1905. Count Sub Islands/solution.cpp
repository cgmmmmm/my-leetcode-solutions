struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m = grid1.size();
        int n = grid1[0].size();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        std::queue<Cell> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid1[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d=0; d<4; ++d)
                        {
                            int ar = r + dr[d];
                            int ac = c + dc[d];

                            if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                            {
                                if (!visited[ar][ac] && grid1[ar][ac] == 1)
                                {
                                    q.push({ar, ac});
                                    visited[ar][ac] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        std::vector<std::vector<bool>> checked(m, std::vector<bool>(n, false));

        int res = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!checked[i][j] && visited[i][j] && grid2[i][j] == 1)
                {
                    bool isSub = true;

                    q.push({i, j});
                    checked[i][j] = true;

                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d=0; d<4; ++d)
                        {
                            int ar = r + dr[d];
                            int ac = c + dc[d];

                            if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                            {
                                if (!checked[ar][ac] && visited[ar][ac] && grid2[ar][ac] == 1)
                                {
                                    q.push({ar, ac});
                                    checked[ar][ac] = true;
                                }
                                else if (!checked[ar][ac] && !visited[ar][ac] && grid2[ar][ac] == 1)
                                {
                                    isSub = false;
                                }
                            }
                        }
                    }

                    if (isSub) res++;
                }
            }
        }

        return res;
    }
};

// during 2nd bfs on grid2, if going up right down left on a visited[i][j] = true cell and landing in a grid[ar][ac] == 1 when visited[ar][ac] == false, that doesnt count as a sub island.