class Solution {
public:
    static constexpr int INF = INT_MAX / 2;

    int minCost(int n) 
    {
        if (n == 0 || n == 1) return 0;

        vector<int> dp(n+1, INF);
        dp[0] = 0, dp[1] = 0;

        for (int x=2; x<=n; ++x)
        {
            dp[x] = std::min(dp[x-1] + x - 1, dp[x]);
        }

        return dp[n];
    }
};

// cost = a * b, where a + b = x
// for all x, the min cost is a = 1, b = x-1 