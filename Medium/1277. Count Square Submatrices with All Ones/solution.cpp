class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::vector<int>>& dp = matrix;

        int res = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (i > 0 && j > 0 && dp[i][j] >= 1)
                {
                    int a = dp[i-1][j], b = dp[i][j-1], c = dp[i-1][j-1];
                    if (a > 0 && b > 0 && c > 0)
                    {
                        dp[i][j] = std::min({a, b, c}) + 1;
                    }
                }

                res += dp[i][j];
            }
        }

        return res;
    }
};

/**

At any arbitrary cell {x, y}, the cell can only form a n * n square when:
    {x-n, y}, {x, y-n}, and {x-n, y-n} are all ones.

This means that at {x, y}, we can use backward DP to determine if there is a n * n square at this cell.

The backward DP will check the precomputed values at a={x-1, y}, b={x, y-1}, and c={x-1, y-1}. The value at {x, y} is min(a,b,c)+1 when a>0, b>0, c>0, and a, b, c are in the boundaries of the input matrix.

e.g1:

0 1 1 1
1 1 2 2
0 1 2 3

sum of all values is the result

e.g2:

1 0 1
1 1 0
1 2 0

sum of all values is the result

*/