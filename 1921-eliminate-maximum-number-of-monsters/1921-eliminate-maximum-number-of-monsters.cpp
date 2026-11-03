class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> times(n, 0);

        for (int i = 0; i < n; i++) {
            times[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        sort(times.begin(), times.end());

        int cnt = 0;

        for (int time = 0; time < n; time++) {
            if (time >= times[time]) {
                break;
            }
            cnt++;
        }

        return cnt;
    }
};