class Solution {
public:

    set<string> combine(set<string> a, set<string> b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> solve(string &s, int &i) {

        set<string> result;
        set<string> current;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                for (string x : current)
                    result.insert(x);

                current.clear();
                i++;
            }

            else if (s[i] == '{') {
                i++;  // skip '{'

                set<string> inside = solve(s, i);

                // Concatenate current with inside
                if (current.empty()) {
                    current = inside;
                }
                else {
                    current = combine(current, inside);
                }

                i++;  // skip '}'
            }

            else {
                // Lowercase letter
                set<string> letter;
                letter.insert(string(1, s[i]));

                if (current.empty()) {
                    current = letter;
                }
                else {
                    current = combine(current, letter);
                }

                i++;
            }
        }

        // Add the last expression
        for (string x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};