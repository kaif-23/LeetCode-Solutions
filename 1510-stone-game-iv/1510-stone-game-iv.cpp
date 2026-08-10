class Solution {
public:
int t[100001];
int solve(int n){
    if(n<=0)return 0;
    if(t[n]!=-1)return t[n];
    for(int i=1; i*i<=n;i++){
        if(solve(n-i*i)==0)return t[n]= 1;
    }
    return t[n]=0;
}
    bool winnerSquareGame(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};