class Solution {
public:
int t[301][5001];
int solve(int i,int amt,vector<int>&coins){
    if(i==coins.size())return 0;
    if(amt==0)return 1;
    if(t[i][amt]!=-1)return t[i][amt];
    int take=0;
    int notake=solve(i+1,amt,coins);
    if(coins[i]<=amt){
     take=solve(i,amt-coins[i],coins);
    }
    return t[i][amt]= take+notake;
}
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};