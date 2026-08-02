class Solution {
public:
int t[501][501];
int solve(vector<int>&nums,int i,int j){
    if(i>j)return 0;
    if(t[i][j]!=-1)return t[i][j];
    int take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
    int take_j=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
    return t[i][j]=max(take_i,take_j);
}
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n=piles.size();
        int total=accumulate(piles.begin(),piles.end(),0);
        int player1=solve(piles,0,n-1);
        int player2=total-player1;
        return player1>=player2;
    }
};