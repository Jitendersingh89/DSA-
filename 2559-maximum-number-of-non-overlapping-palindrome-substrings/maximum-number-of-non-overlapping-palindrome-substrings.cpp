class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (len == 1) {
                    pal[i][j] = true;
                }
                else if (len == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using the first i characters
        vector<int> dp(n + 1, 0);

        for (int end = 1; end <= n; end++) {

            // Don't use a palindrome ending at end-1
            dp[end] = dp[end - 1];

            for (int start = 0; start < end; start++) {

                int len = end - start;

                if (len >= k && pal[start][end - 1]) {
                    dp[end] = max(dp[end],
                                  dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};