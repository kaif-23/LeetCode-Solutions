class Solution {
public:
int t[21][20001];
 int solve(int i,vector<int>&nums,int target,int sum,int offset){
    if(i==nums.size()){
        return (sum==target)?1:0;
    }
    if(t[i][sum+offset]!=-1)return t[i][sum+offset];
    int plus=solve(i+1,nums,target,sum+nums[i],offset);
    int minus=solve(i+1,nums,target,sum-nums[i],offset);
    return t[i][sum+offset]= plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        int tSum=accumulate(nums.begin(),nums.end(),0);
        if(tSum<abs(target))return 0;
        return solve(0,nums,target,0,tSum);
    }
};