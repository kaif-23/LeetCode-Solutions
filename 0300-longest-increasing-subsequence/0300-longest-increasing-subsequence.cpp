class Solution {
public:
int t[2501][2501];
int solve(vector<int>&nums,int i,int prev){
    if(i==nums.size())return 0;
    
    if(prev!=-1&&t[i][prev]!=-1){
        return t[i][prev];
    }
    int skip=solve(nums,i+1,prev);

    int take=0;

    if(prev==-1||nums[i]>nums[prev]){
        take=1+solve(nums,i+1,i);  
    }
    if(prev!=-1){
        t[i][prev]=max(skip,take);
    }
    return  max(skip,take);

}
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
       return  solve(nums,0,-1);
    }
};