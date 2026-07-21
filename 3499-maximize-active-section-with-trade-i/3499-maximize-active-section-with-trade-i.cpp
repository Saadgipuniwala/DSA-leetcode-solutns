class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        // Augment the string
        s = "1" + s + "1";

        vector<pair<char, int>> blocks;

        // Run Length Encoding
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                blocks.push_back({s[i - 1], cnt});
                cnt = 1;
            }
        }
        blocks.push_back({s.back(), cnt});

        int ans = ones;

        // Check every pattern: 0-block, 1-block, 0-block
        for (int i = 1; i + 1 < blocks.size(); i++) {

            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                ans = max(ans,
                          ones + blocks[i - 1].second + blocks[i + 1].second);
            }
        }

        return ans;
    }
};