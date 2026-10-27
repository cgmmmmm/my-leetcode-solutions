#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> q(m * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        int max_area = 0;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int area = 1;

                    int head = 0, tail = 0;

                    q[tail++] = i * n + j;
                    grid[i][j] = 0;

                    while (head < tail)
                    {
                        int curr = q[head++];
                        int x = curr / n;
                        int y = curr % n;
                        
                        for (int d=0; d<4; ++d)
                        {
                            int ar = x + dr[d];
                            int ac = y + dc[d];

                            if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                            {
                                if (grid[ar][ac] == 1)
                                {
                                    area++;
                                    grid[ar][ac] = 0;
                                    q[tail++] = ar * n + ac;
                                }
                            }
                        }
                    }

                    max_area = std::max(area, max_area);
                }
            }
        }

        return max_area;
    }
};