class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int sr = 0;
        int sc = 0;
        int er = row - 1;
        int ec = col - 1;

        while (count < total) {

            // Starting Row
            for (int ind = sc; ind <= ec && count < total; ind++) {
                ans.push_back(matrix[sr][ind]);
                count++;
            }
            sr++;

            // Ending Column
            for (int ind = sr; ind <= er && count < total; ind++) {
                ans.push_back(matrix[ind][ec]);
                count++;
            }
            ec--;

            // Ending Row
            for (int ind = ec; ind >= sc && count < total; ind--) {
                ans.push_back(matrix[er][ind]);
                count++;
            }
            er--;

            // Starting Column
            for (int ind = er; ind >= sr && count < total; ind--) {
                ans.push_back(matrix[ind][sc]);
                count++;
            }
            sc++;
        }

        return ans;
    }
};