class Solution {
public:
   int solve(int step,vector<int>&cost,vector<int>&dp){
    if(step>=cost.size()){
        return 0;
    }
    if(dp[step]!=-1){
        return dp[step];
    }
    return dp[step]=cost[step]+min(solve(step+1,cost,dp),solve(step+2,cost,dp));
   }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
         return min(
            solve(0, cost, dp),
            solve(1, cost, dp)
        );
    }
};