class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;
    };

    vector<Node> seg;

    Node merge(Node L, Node R) {

        Node res;

        res.len = L.len + R.len;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Initially prefix and suffix come from their respective sides
        res.prefix = L.prefix;
        res.suffix = R.suffix;

        // Best answer is either completely in left or completely in right
        res.best = max(L.best, R.best);

        // If characters at the boundary are equal
        if (L.rightChar == R.leftChar) {

            // A repeating substring can cross the boundary
            res.best = max(res.best, L.suffix + R.prefix);

            // Entire left segment can extend into right
            if (L.prefix == L.len) {
                res.prefix = L.len + R.prefix;
            }

            // Entire right segment can extend into left
            if (R.suffix == R.len) {
                res.suffix = R.len + L.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {

            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {

            seg[node].leftChar = c;
            seg[node].rightChar = c;

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
