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
        
        int res = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    bool is_sub = true;

                    q.push({i, j});
                    grid2[i][j] = 0;

                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        if (grid1[r][c] == 0) is_sub = false;

                        for (int d=0; d<4; ++d)
                        {
                            int ar = r + dr[d];
                            int ac = c + dc[d];

                            if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                            {
                                if (grid2[ar][ac] == 1)
                                {
                                    grid2[ar][ac] = 0;
                                    q.push({ar, ac});
                                }
                            }
                        }
                    }

                    if (is_sub) res++;
                }
            }
        }

        return res;
    }
};

// during 2nd bfs on grid2, if going up right down left on a visited[i][j] = true cell and landing in a grid2[ar][ac] == 1 when visited[ar][ac] == false, that doesnt count as a sub island.

// optimize:
// 1. modify grid val to 0 to signify visited
// 2. if grid2[r][c] == 1 but grid1[r][c] == 0, not a sub island