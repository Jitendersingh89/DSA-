class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = index in word1 where word2[j]
        // can be matched while still matching the suffix.
        vector<int> last(m, -1);

        // Build last[] from right to left
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // Now greedily build the answer
        bool usedMismatch = false;

        j = 0;

        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Case 1:
            // Characters match, so take this index.
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Case 2:
            // Characters don't match.
            // We can use our one allowed mismatch
            // only if the remaining suffix can still be matched.
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;

                j++;

                usedMismatch = true;
            }
        }

        // Couldn't match all characters
        if (j != m)
            return {};

        return ans;
    }
};