class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Build prefix sum
        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Initially, choose all stones
        int dp = prefix[n - 1];

        // Try every possible stopping point
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};