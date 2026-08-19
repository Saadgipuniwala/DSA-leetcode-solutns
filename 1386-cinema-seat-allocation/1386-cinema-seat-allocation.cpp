class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;

        // Store reserved seats of each row using bitmask
        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            mp[row] |= (1 << seat);
        }

        // Every completely empty row can have 2 groups
        int ans = 2 * n;

        // Possible blocks
        int left  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Check only rows having reservations
        for (auto &[row, mask] : mp) {

            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                // Already counted 2
            }
            else if (canLeft || canMiddle || canRight) {
                // Can fit only 1 group
                ans--;
            }
            else {
                // Cannot fit any group
                ans -= 2;
            }
        }

        return ans;
    }
};