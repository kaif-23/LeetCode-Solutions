class Solution {
public:
    
    vector<int> cache;
    int res = 0;
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        // sort by start time
        sort(jobs.begin(), jobs.end());
        
        cache = vector<int>(n, -1);
        
        helper(jobs, 0);
        return res;
    }
    
    int helper(vector<vector<int>>& jobs, int idx) {
        if (idx == jobs.size()) {
            return 0;
        }
        
        if (cache[idx] != -1) {
            return cache[idx];
        }
        
        // if schedule the current, then need to find the next that has start time > current end time
        int next_idx = find_next(jobs, jobs[idx][1]);
        int select = helper(jobs, next_idx) + jobs[idx][2];
        // if not, directly move the next job
        int not_select = helper(jobs, idx+1);
        
        cache[idx] = max(select, not_select);
        
        res = max(res, cache[idx]);
        
        return cache[idx];
    }
    
    // binary search to find the next possible job
    // next job's start time >= current job end time
    int find_next(vector<vector<int>>& jobs, int t) {
        int l = 0, r = jobs.size();
        while (l < r) {
            int m = l + (r-l)/2;
            if (jobs[m][0] >= t) {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        return l;
    }
    
};