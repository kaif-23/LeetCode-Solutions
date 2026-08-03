class Solution {
public:
int n;
int t[50001];
int solve(vector<int>& nums,int i){
    if(i>=n)return 0;
    if(t[i]!=-1)return t[i];
    int res=INT_MIN;
    res=max(res,(nums[i]-solve(nums,i+1)));
    if(i+1<n){
    res=max(res,(nums[i]+nums[i+1] -solve(nums,i+2)));
    }
    if(i+2<n){
    res=max(res,(nums[i]+nums[i+1]+nums[i+2] -solve(nums,i+3)));
    }
    return t[i]=res;
}
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(t,-1,sizeof(t));
        int diff=solve(stoneValue,0);

        if(diff>0)return "Alice";
        if(diff<0) return "Bob";
        return "Tie";
    }
};