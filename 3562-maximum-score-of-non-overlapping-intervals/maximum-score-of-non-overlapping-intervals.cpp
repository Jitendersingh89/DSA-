class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending position
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        // prev[i] = last interval that doesn't overlap with i
        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++) {
            int l = a[i][0];

            int lo = 0, hi = i - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][1] < l) {
                    prev[i] = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        // dp[i][k] = best answer using first i intervals
        // with at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5, {0, {}})
        );

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take current interval
                dp[i][k] = dp[i - 1][k];

                // Option 2: Take current interval
                int j = prev[i - 1] + 1;

                auto candidate = dp[j][k - 1];

                candidate.first += a[i - 1][2];
                candidate.second.push_back((int)a[i - 1][3]);

                // Indices must be sorted for lexicographical comparison
                sort(candidate.second.begin(), candidate.second.end());

                // Better score OR same score with smaller indices
                if (candidate.first > dp[i][k].first ||
                    (candidate.first == dp[i][k].first &&
                     candidate.second < dp[i][k].second)) {
                    dp[i][k] = candidate;
                }
            }
        }

        return dp[n][4].second;
    }
};