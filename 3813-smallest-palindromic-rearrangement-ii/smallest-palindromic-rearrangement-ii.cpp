class Solution {
public:
    static constexpr int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        string left;
        int len = 0;

        for (int x : half)
            len += x;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                int ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }

private:
    int countWays(vector<int>& freq) {

        int total = 0;
        for (int x : freq)
            total += x;

        long long res = 1;

        for (int x : freq) {

            if (x == 0)
                continue;

            res *= nCr(total, x);

            if (res >= MAX)
                return MAX;

            total -= x;
        }

        return (int)res;
    }

    long long nCr(int n, int r) {

        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {

            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }

        return res;
    }
};