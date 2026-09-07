class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';

            long long newCount = (total + 1) % MOD;

            // Remove the old subsequences ending in c
            total = (total - dp[idx] + MOD) % MOD;

            // Add the new subsequences ending in c
            dp[idx] = newCount;

            total = (total + dp[idx]) % MOD;
        }

        return total;
    }
};
