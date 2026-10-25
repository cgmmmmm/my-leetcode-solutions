struct Cell {
    int row;
    int col;
};

class Solution {
public:
    bool bfs(
            std::queue<Cell>& q, 
            std::vector<std::vector<bool>>& visited,
            const std::vector<std::vector<int>>& grid, 
            const int r, 
            const int c,
            const int startRow,
            const int startCol)
    {
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        bool isClosed = true;
        while (!q.empty())
        {
            Cell curr = q.front();
            q.pop();

            int x = curr.row;
            int y = curr.col;
            if (x == 0 || y == 0 || x == r-1 || y == c-1)
            {
                isClosed = false;
            }

            for (int i=0; i<4; ++i)
            {
                int ar = x + dr[i];
                int ac = y + dc[i];

                if (ar >= 0 && ar < r && ac >= 0 && ac < c)
                {
                    if (!visited[ar][ac] && grid[ar][ac] == 0)
                    {
                        visited[ar][ac] = true;
                        q.push({ar, ac});
                    }
                }
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();

        std::queue<Cell> q;
        std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));

        int res = 0;
        for (int i=0; i<r; ++i)
        {
            for (int j=0; j<c; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    if (bfs(q, visited, grid, r, c, i, j))
                    {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};