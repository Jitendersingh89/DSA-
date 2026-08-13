class Solution {
    struct Node {
        char leftChar = 0;
        char rightChar = 0;

        int pref = 0;
        int suff = 0;
        int best = 0;
        int len = 0;
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        res.best = max(a.best, b.best);

        // Can combine across the boundary
        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.suff + b.pref);

            // Entire left segment has same character
            if (a.pref == a.len) {
                res.pref = a.len + b.pref;
            }

            // Entire right segment has same character
            if (b.suff == b.len) {
                res.suff = b.len + a.suff;
            }
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];

            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node].leftChar = c;
            seg[node].rightChar = c;

            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};