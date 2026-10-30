struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        std::queue<Cell> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        std::vector<int> mappings(1, 0);
        std::vector<std::vector<std::set<int>>> surround(m, std::vector<std::set<int>>(n));

        int islandID = 1;
        int max_area = 1;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int area = 1;

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
                                if (!visited[ar][ac] && grid[ar][ac] == 1)
                                {
                                    visited[ar][ac] = true;
                                    area += 1;
                                    q.push({ar, ac});
                                }

                                if (grid[ar][ac] == 0)
                                {
                                    surround[ar][ac].insert(islandID);
                                }
                            }
                        }
                    }

                    mappings.push_back(area);
                    islandID += 1;
                    max_area = std::max(max_area, area);
                }
            }
        }

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!surround[i][j].empty())
                {
                    int area = 1;

                    for (int id : surround[i][j])
                    {
                        area += mappings[id];
                    }

                    max_area = std::max(max_area, area);
                }
            }
        }

        return max_area;
    }
};