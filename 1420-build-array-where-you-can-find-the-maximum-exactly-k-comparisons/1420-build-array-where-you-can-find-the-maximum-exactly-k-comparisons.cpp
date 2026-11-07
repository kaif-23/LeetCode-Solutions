class Solution {
public:
    int t[51][51][101];
    int MOD = 1e9 + 7;
    int solve(int i, int cost, int maxVal, int m, int k, int n) {
        if (i == n) {
            if (cost == k)
                return 1;
            return 0;
        }
        if (t[i][cost][maxVal] != -1)
            return t[i][cost][maxVal];
        int ans = 0;
        for (int num = 1; num <= m; num++) {
            if (num > maxVal) {
                ans=(ans + solve(i + 1, cost + 1, num, m, k, n)) % MOD;
            } else {
               ans= (ans + solve(i + 1, cost, maxVal, m, k, n)) % MOD;
            }
        }
        return t[i][cost][maxVal] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, m, k, n);
    }
};