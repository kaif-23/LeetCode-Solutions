class Solution {
public:
    // int n;
    // int t[100001];
    // int solve(int x, vector<int>& prefix) {
    //     if (x == n - 1)
    //         return prefix[n - 1];

    //     if (t[x] != -1)
    //         return t[x];
    //     int take = prefix[x] - solve(x + 1, prefix);
    //     int skip = solve(x + 1, prefix);
    //     return t[x] = max(take, skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n);
        // memset(t, -1, sizeof(t));

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        vector<int> t(n, 0);
        t[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = prefix[i] - t[i + 1];
            int skip = t[i + 1];
            t[i] = max(take, skip);
        }

        return t[1];
    }
};