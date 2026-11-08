class Solution {
public:
    int solve(int index, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp, int cnt,int k) {

        if (index == prices.size() || cnt == k)
            return 0;

        if (dp[index][buy][cnt] != -1)
            return dp[index][buy][cnt];

        int profit = 0;

        if (buy) {

            int buykaro = -prices[index] +
                          solve(index+1, 0, prices, dp, cnt,k);

            int skipkaro =
                solve(index+1, 1, prices, dp, cnt,k);

            profit = max(buykaro, skipkaro);

        } else {

            int sellkaro = prices[index] +
                           solve(index+1, 1, prices, dp, cnt+1,k);

            int skipkaro =
                solve(index+1, 0, prices, dp, cnt,k);

            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy][cnt] = profit;
    }

    int maxProfit(int k,vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k, -1))
        );

        return solve(0, 1, prices, dp, 0,k);
    }
};