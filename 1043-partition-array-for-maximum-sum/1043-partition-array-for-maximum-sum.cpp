class Solution {
public:
int dp[501];
int solve(vector<int>&arr,int l,int k){
    if(l>=arr.size()){
        return 0;
    }
    if(dp[l]!=-1)return dp[l];
    int res=-1;
    int currMax=-1;
    for(int idx=l; idx <arr.size() && idx-l+1<=k;idx++){
       currMax=max(currMax,arr[idx]);
        int cost =(currMax*(idx-l+1))+solve(arr,idx+1,k);
        res=max(cost,res);
    }
    return dp[l]=res;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
};