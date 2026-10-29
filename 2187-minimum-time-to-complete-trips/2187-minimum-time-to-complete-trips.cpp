class Solution {
public:
    bool solve(vector<int>& time, int totalTrips, long long mid) {
        long long cnt = 0;

        for (int x : time) {
            cnt += mid / x;

            if (cnt >= totalTrips)
                return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = 1LL * (*min_element(time.begin(), time.end()))
                      * totalTrips;

        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (solve(time, totalTrips, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};