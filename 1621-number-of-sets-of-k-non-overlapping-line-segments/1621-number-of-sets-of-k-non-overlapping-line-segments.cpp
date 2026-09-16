class Solution {
public:
const int MOD=1e9+7;
int t[1001][1001];
int solve(int n,int k,int i){
    if(k==0)return 1;
    if(i>=n)return 0;
    if(t[i][k]!=-1)return t[i][k];
    int skip=(solve(n,k,i+1))%MOD;
    int take=0;
    for(int j=i+1;j<n;j++){
     take =(take+solve(n,k-1,j))%MOD;
    }
    return t[i][k]= (skip+take)%MOD;
}
    int numberOfSets(int n, int k) {
        memset(t,-1,sizeof(t));
        if(k==n-1)return 1;
        return solve(n,k,0)%MOD;
    }
};