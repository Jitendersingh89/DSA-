class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        // Count characters
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // A palindrome is possible only if at most one
        // character has an odd frequency.
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        // Build palindrome from a given left half
        auto makePalindrome = [&](string left) {
            string right = left;
            reverse(right.begin(), right.end());

            if (n % 2)
                return left + string(1, middle) + right;
            else
                return left + right;
        };

        // --------------------------------------------------
        // CASE 1:
        // Try using target's left half exactly.
        // --------------------------------------------------

        vector<int> rem = halfCnt;
        string left = "";

        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
            left += target[i];
        }

        if (possible) {
            string candidate = makePalindrome(left);

            if (candidate > target)
                return candidate;
        }

        // --------------------------------------------------
        // CASE 2:
        // Find the rightmost position where we can increase
        // target[i].
        // --------------------------------------------------

        for (int i = m - 1; i >= 0; i--) {

            // Reconstruct remaining counts after keeping
            // target[0 ... i-1].
            rem = halfCnt;

            bool prefixPossible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                rem[x]--;
            }

            if (!prefixPossible)
                continue;

            // Find the smallest character > target[i]
            // that is still available.
            int current = target[i] - 'a';

            int bigger = -1;

            for (int c = current + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            // Construct the left half
            string newLeft = target.substr(0, i);

            newLeft += char('a' + bigger);
            rem[bigger]--;

            // Fill remaining positions with smallest chars
            for (int c = 0; c < 26; c++) {
                while (rem[c] > 0) {
                    newLeft += char('a' + c);
                    rem[c]--;
                }
            }

            return makePalindrome(newLeft);
        }

        return "";
    }
};