class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {

        int n = nums.size();

        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {

            if (i + j < n) {

                int next = solve(i + j, nums, dp);

                if (next != INT_MAX) {
                    ans = min(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};