class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            long long take1 = INT_MAX;
            long long take2 = INT_MAX;
            long long take3 = INT_MAX;

            int j = i + 1;
            if (j <= n) {
                take1 = costs[j - 1] + (j - i) * (j - i) + dp[j];
            }

            j = i + 2;
            if (j <= n) {
                take2 = costs[j - 1] + (j - i) * (j - i) + dp[j];
            }

            j = i + 3;
            if (j <= n) {
                take3 = costs[j - 1] + (j - i) * (j - i) + dp[j];
            }

            dp[i] = min({take1, take2, take3});
        }

        return dp[0];
    }
};