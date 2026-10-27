#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        std::vector<int> q;
        q.reserve(m * n);

        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};

        int max_area = 0;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int area = 1;

                    int head = 0, tail = 0;

                    if (q.empty()) q.resize(m * n); 
                    
                    q[tail++] = (i << 16) | j;
                    grid[i][j] = 0;

                    while (head < tail)
                    {
                        int curr = q[head++];
                        int x = curr >> 16;
                        int y = curr & 0xFFFF;
                        
                        for (int d=0; d<4; ++d)
                        {
                            int ar = x + dr[d];
                            int ac = y + dc[d];

                            if (static_cast<unsigned>(ar) < static_cast<unsigned>(m) && 
                                static_cast<unsigned>(ac) < static_cast<unsigned>(n)) 
                            {
                                if (grid[ar][ac] == 1)
                                {
                                    area++;
                                    grid[ar][ac] = 0;
                                    q[tail++] = (ar << 16) | ac;
                                }
                            }
                        }
                    }

                    if (area > max_area)
                    {
                        max_area = area;
                    }
                }
            }
        }

        return max_area;
    }
};