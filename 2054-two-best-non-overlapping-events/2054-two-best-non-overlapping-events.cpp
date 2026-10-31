class Solution {
public:
    int findEvents(vector<vector<int>>& events, int idx, int cnt,
                   vector<vector<int>>& dp) {

        if (cnt == 2 || idx >= events.size())
            return 0;

        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        int end = events[idx][1];

        int lo = idx + 1;
        int hi = events.size();

        // Find first event with start > current end
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (events[mid][0] > end)
                hi = mid;
            else
                lo = mid + 1;
        }

        int include = events[idx][2] +
                      findEvents(events, lo, cnt + 1, dp);

        int exclude = findEvents(events, idx + 1, cnt, dp);

        return dp[idx][cnt] = max(include, exclude);
    }

    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        vector<vector<int>> dp(events.size(), vector<int>(2, -1));

        return findEvents(events, 0, 0, dp);
    }
};