class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lt = 0, eq = 0;
        for (int x : nums) {
            if (x < target) lt++;
            else if (x == target) eq++;
        }
        vector<int> res;
        res.reserve(eq);
        for (int i = 0; i < eq; i++) res.push_back(lt + i);
        return res;
    }
};