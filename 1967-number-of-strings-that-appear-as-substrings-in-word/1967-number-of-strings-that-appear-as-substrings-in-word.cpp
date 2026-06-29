class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for(int i = 0; i < patterns.size(); i++) {
            //searches b in a i.e: a.find(b)
            if(word.find(patterns[i]) != string::npos) {
                ans++;
            }
        }

        return ans;
    }
};