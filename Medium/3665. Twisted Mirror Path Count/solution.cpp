class Solution {
public:
    std::pair<int, int> getMoveDestination(int x, int y, int dir,
                const std::vector<std::vector<int>>& grid,
                const int m,
                const int n)
    {
        if (x >= m || y >= n || x < 0 || y < 0) return {-1, -1};

        if (grid[x][y] == 0) return {x, y};

        return (dir == 0) ? getMoveDestination(x+1, y, 1, grid, m, n) : getMoveDestination(x, y+1, 0, grid, m, n);
    }

    int uniquePaths(std::vector<std::vector<int>>& grid) 
    {
        constexpr int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        // move[i][j][0] = right, move[i][j][1] = down
        std::vector<std::vector<std::vector<std::pair<int, int>>>> move(
            m, std::vector<std::vector<std::pair<int, int>>>(
                n, std::vector<std::pair<int, int>>(2, {-1, -1})
            )
        );

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] != 0) continue;

                move[i][j][0] = getMoveDestination(i, j+1, 0, grid, m, n);
                move[i][j][1] = getMoveDestination(i+1, j, 1, grid, m, n);
            }
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (dp[i][j] == 0) continue;

                const auto& [rx, ry] = move[i][j][0];
                if (rx != -1 && ry != -1)
                {
                    dp[rx][ry] = (dp[rx][ry] + dp[i][j]) % MOD;
                }

                const auto& [dx, dy] = move[i][j][1];
                if (dx != -1 && dy != -1)
                {
                    dp[dx][dy] = (dp[dx][dy] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m-1][n-1];
    }
};