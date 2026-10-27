#include <vector>
#include <queue>

struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int bfs(std::vector<std::vector<bool>>& visited,
            const std::vector<std::vector<int>>& grid,
            const int startRow,
            const int startCol,
            const int m,
            const int n)
    {
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        std::queue<Cell> q;

        q.push({startRow, startCol});
        visited[startRow][startCol] = true;
        
        int area = 1;

        while (!q.empty())
        {
            Cell curr = q.front();
            q.pop();

            int x = curr.row;
            int y = curr.col;
            
            for (int i=0; i<4; ++i)
            {
                int ar = x + dr[i];
                int ac = y + dc[i];

                if (ar >= 0 && ar < m && ac >= 0 && ac < n)
                {
                    if (!visited[ar][ac] && grid[ar][ac] == 1)
                    {
                        area++;
                        visited[ar][ac] = true;
                        q.push({ar, ac});
                    }
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        int max_area = 0;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    max_area = std::max(bfs(visited, grid, i, j, m, n), 
                                        max_area);
                }
            }
        }

        return max_area;
    }
};