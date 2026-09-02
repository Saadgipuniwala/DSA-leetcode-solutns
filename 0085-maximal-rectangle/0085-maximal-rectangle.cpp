class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currHeight) {

                int h = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Update histogram
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Largest rectangle in histogram
            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};