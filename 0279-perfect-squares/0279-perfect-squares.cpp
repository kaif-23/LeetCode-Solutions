class Solution {
public:
    int m;
    int t[10001];

    int solve(int sum, int n) {
        if (sum == n) return 0;
        if (sum > n) return INT_MAX;

        if (t[sum] != -1) return t[sum];

        int mini = INT_MAX;

        for (int j = 1; j <= m; j++) {
            if (sum + j * j <= n) {
                int res = solve(sum + j * j, n);

                if (res != INT_MAX) {
                    mini = min(mini, 1 + res);
                }
            }
        }

        return t[sum] = mini;
    }

    int numSquares(int n) {
        memset(t, -1, sizeof(t));
        m = sqrt(n);

        return solve(0, n);
    }
};