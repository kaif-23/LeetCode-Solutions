class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& matrix) {

        if (j < 0 || j >= n)
            return 1e9;

        if (i == n - 1)
            return matrix[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int left = solve(i + 1, j - 1, matrix);
        int down = solve(i + 1, j, matrix);
        int right = solve(i + 1, j + 1, matrix);

        return dp[i][j] = matrix[i][j] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix));
        }

        return ans;
    }
};