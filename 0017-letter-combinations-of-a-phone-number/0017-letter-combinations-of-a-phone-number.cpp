class Solution {
public:
    vector<string> ans;

    void solve(string &digits, int index, string &temp, vector<string> &mapping) {
        // Base case
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            temp.push_back(ch);
            solve(digits, index + 1, temp, mapping);
            temp.pop_back(); // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string temp = "";
        solve(digits, 0, temp, mapping);

        return ans;
    }
};