class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        long long ans = (long long)(n - mp.size()) * 2;

        for (auto &row : mp) {

            auto &s = row.second;

            bool left =
                s.count(2) == 0 &&
                s.count(3) == 0 &&
                s.count(4) == 0 &&
                s.count(5) == 0;

            bool middle =
                s.count(4) == 0 &&
                s.count(5) == 0 &&
                s.count(6) == 0 &&
                s.count(7) == 0;

            bool right =
                s.count(6) == 0 &&
                s.count(7) == 0 &&
                s.count(8) == 0 &&
                s.count(9) == 0;

            if (left && right) {
                ans += 2;
            } else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};