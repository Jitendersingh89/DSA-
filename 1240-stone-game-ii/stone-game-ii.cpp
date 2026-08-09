#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> memo;

    int solve(int i, int M) {
        // Base Case: If remaining piles are <= 2M, take all remaining stones
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        // Return memoized result if available
        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;

        // Try taking X piles (1 <= X <= 2M)
        for (int X = 1; X <= 2 * M; X++) {
            // Next player gets solve(i + X, max(M, X))
            // Current player gets suffixSum[i] - next_player's_max
            int currentStones = suffixSum[i] - solve(i + X, max(M, X));
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.resize(n);
        
        // Compute Suffix Sums
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Initialize memo table with -1
        // Note: M never exceeds n
        memo.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};