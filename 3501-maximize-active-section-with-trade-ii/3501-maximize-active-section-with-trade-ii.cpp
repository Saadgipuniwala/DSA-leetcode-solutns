#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    // Finds the first index where ends[i] >= target
    int lowerBoundEnds(const vector<int>& ends, int target) {
        int low = 0, high = (int)ends.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ends[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Finds the last index where starts[i] <= target
    int upperBoundStarts(const vector<int>& starts, int target) {
        int low = 0, high = (int)starts.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (starts[mid] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = 0;
        
        vector<pair<int, int>> zeroBlocksList;
        int start = -1;
        
        // Find all contiguous blocks of '0's and count total '1's
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (start == -1) start = i;
            } else {
                totalOnes++;
                if (start != -1) {
                    zeroBlocksList.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if (start != -1) {
            zeroBlocksList.push_back({start, n - 1});
        }
        
        int m = zeroBlocksList.size();
        vector<int> starts(m);
        vector<int> ends(m);
        for (int i = 0; i < m; i++) {
            starts[i] = zeroBlocksList[i].first;
            ends[i] = zeroBlocksList[i].second;
        }
        
        // Precompute pair sums and build a Sparse Table for O(1) Range Maximum Queries
        vector<vector<int>> st;
        vector<int> log2;
        
        if (m > 1) {
            vector<int> pairSums(m - 1);
            for (int i = 0; i < m - 1; i++) {
                pairSums[i] = (ends[i] - starts[i] + 1) + (ends[i + 1] - starts[i + 1] + 1);
            }
            
            int maxLog = 0;
            while ((1 << maxLog) <= (m - 1)) {
                maxLog++;
            }
            
            st.assign(m - 1, vector<int>(maxLog, 0));
            log2.assign(m + 1, 0);
            
            for (int i = 2; i <= m; i++) {
                log2[i] = log2[i / 2] + 1;
            }
            
            for (int i = 0; i < m - 1; i++) {
                st[i][0] = pairSums[i];
            }
            
            for (int j = 1; j < maxLog; j++) {
                for (int i = 0; i + (1 << j) <= m - 1; i++) {
                    st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            
            // Binary search to find the first block ending >= l
            int firstBlock = lowerBoundEnds(ends, l);
            // Binary search to find the last block starting <= r
            int lastBlock = upperBoundStarts(starts, r);
            
            int maxGain = 0;
            
            if (firstBlock != -1 && lastBlock != -1 && firstBlock < lastBlock) {
                if (firstBlock + 1 == lastBlock) {
                    // Exactly two blocks intersect the query
                    int len1 = min(r, ends[firstBlock]) - max(l, starts[firstBlock]) + 1;
                    int len2 = min(r, ends[lastBlock]) - max(l, starts[lastBlock]) + 1;
                    maxGain = len1 + len2;
                } else {
                    // More than two blocks intersect the query
                    
                    // Left boundary pair (first intersecting block + the one immediately after)
                    int lenFirst = min(r, ends[firstBlock]) - max(l, starts[firstBlock]) + 1;
                    int lenSecond = ends[firstBlock + 1] - starts[firstBlock + 1] + 1;
                    maxGain = max(maxGain, lenFirst + lenSecond);
                    
                    // Right boundary pair (last intersecting block + the one immediately before)
                    int lenSecondLast = ends[lastBlock - 1] - starts[lastBlock - 1] + 1;
                    int lenLast = min(r, ends[lastBlock]) - max(l, starts[lastBlock]) + 1;
                    maxGain = max(maxGain, lenSecondLast + lenLast);
                    
                    // Intermediate pairs fully inside the interval
                    int L = firstBlock + 1;
                    int R = lastBlock - 2;
                    if (L <= R) {
                        int j = log2[R - L + 1];
                        int maxInternal = max(st[L][j], st[R - (1 << j) + 1][j]);
                        maxGain = max(maxGain, maxInternal);
                    }
                }
            }
            
            answer.push_back(totalOnes + maxGain);
        }
        
        return answer;
    }
};