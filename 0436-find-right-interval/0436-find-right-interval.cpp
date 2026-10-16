class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        
        // 1. Store {start_time, original_index} for each interval
        vector<pair<int, int>> sortedIntervals;
        for (int i = 0; i < n; ++i) {
            sortedIntervals.push_back({intervals[i][0], i});
        }
        
        // 2. Sort based on the start times (pairs sort by first element by default)
        sort(sortedIntervals.begin(), sortedIntervals.end());
        
        // 3. For each interval, look for the smallest start time >= current end time
        for (int i = 0; i < n; ++i) {
            int target_end = intervals[i][1];
            
            // Search for a pair where pair.first >= target_end
            auto it = lower_bound(sortedIntervals.begin(), sortedIntervals.end(), 
                                  make_pair(target_end, -1));
            
            if (it != sortedIntervals.end()) {
                res[i] = it->second; // Get the original index stored in pair.second
            }
        }
        
        return res; // 4. Return the completed result array
    }
};
