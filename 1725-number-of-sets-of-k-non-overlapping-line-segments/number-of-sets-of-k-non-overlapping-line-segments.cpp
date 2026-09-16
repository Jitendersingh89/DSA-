class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        // dp[i][j] = number of ways to make j segments
        // using first i points (0 ... i-1)
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

        // 0 segments can always be formed in 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i <= n; i++) {

                // Don't use point i-1 as the ending point
                dp[i][j] = dp[i - 1][j];

                // Add possibilities where a segment ends at i-1
                if (i >= 2) {
                    sum = (sum + dp[i - 1][j - 1]) % MOD;
                    dp[i][j] = (dp[i][j] + sum) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};
