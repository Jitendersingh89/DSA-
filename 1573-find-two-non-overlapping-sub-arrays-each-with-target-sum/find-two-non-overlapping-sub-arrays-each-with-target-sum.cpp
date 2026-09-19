class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int left = 0;
        int sum = 0;

        const int INF = 1e9;

        vector<int> best(n + 1, INF);

        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward previous best
            best[right + 1] = best[right];

            // Found a subarray with sum = target
            if (sum == target) {

                int len = right - left + 1;

                // Combine with a previous non-overlapping subarray
                if (best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }

                // Store current subarray as a possible best
                best[right + 1] = min(best[right + 1], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};