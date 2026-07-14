class Solution {
public:
const static int MOD=1e9+7;
int t[201][201][201];
int solve(vector<int>&nums,int idx,int f_gcd,int s_gcd){
    if(idx==nums.size()){
        bool bothnonEmpty=(f_gcd!=0 && s_gcd!=0);
        bool equalGcd=(f_gcd==s_gcd);
        return (bothnonEmpty&&equalGcd)?1:0;
    }
    if(t[idx][f_gcd][s_gcd]!=-1){
        return t[idx][f_gcd][s_gcd];
    }
    int skip=solve(nums,idx+1,f_gcd,s_gcd);
    int seq1=solve(nums,idx+1,__gcd(f_gcd,nums[idx]),s_gcd);
    int seq2=solve(nums,idx+1,f_gcd,__gcd(s_gcd,nums[idx]));
    return t[idx][f_gcd][s_gcd]=(0LL+skip+seq1+seq2)%MOD;
}
    int subsequencePairCount(vector<int>& nums) {
  memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);

    }
};