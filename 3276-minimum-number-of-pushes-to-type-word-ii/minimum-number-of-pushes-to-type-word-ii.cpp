class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        // Assign most frequent letters to lowest push cost
        for (int i = 0; i < 26; i++) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};