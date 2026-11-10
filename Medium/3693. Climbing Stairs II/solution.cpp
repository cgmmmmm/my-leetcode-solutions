class Solution {
public:
    static constexpr int INF = 1e9;

    int climbStairs(int n, vector<int>& costs) 
    {
        std::vector<int> dp(n+1, INF);
        dp[0] = 0;

        for (int i=0; i<n; ++i)
        {
            int j1=i+1, j2=i+2, j3=i+3;
            
            if (j1 <= n) dp[j1] = std::min(dp[i] + costs[j1-1] + (j1 - i) * (j1 - i), dp[j1]);
            if (j2 <= n) dp[j2] = std::min(dp[i] + costs[j2-1] + (j2 - i) * (j2 - i), dp[j2]);
            if (j3 <= n) dp[j3] = std::min(dp[i] + costs[j3-1] + (j3 - i) * (j3 - i), dp[j3]);
        }

        return dp[n];
    }
};

// cost = costs[j] + (j - i)^2