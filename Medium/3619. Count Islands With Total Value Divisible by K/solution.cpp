using ll = long long;

struct Cell {
    int row;
    int col;
};

class Solution {
public:
    // ll bfs() returns sum of island
    ll bfs(std::queue<Cell>& q,
            std::vector<std::vector<bool>>& visited,
            const std::vector<std::vector<int>>& grid,
            const int m,
            const int n,
            const int startRow,
            const int startCol)
    {
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        ll sum = grid[startRow][startCol];
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
                    if (!visited[ar][ac] && grid[ar][ac] > 0)
                    {
                        sum += grid[ar][ac];
                        visited[ar][ac] = true;
                        q.push({ar, ac});
                    }
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();
        int n = grid[0].size();

        std::queue<Cell> q;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        int res = 0;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] > 0)
                {
                    if (bfs(q, visited, grid, m, n, i, j) % k == 0) res++;
                }
            }
        }

        return res;
    }
};