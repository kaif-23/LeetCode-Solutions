class Solution {
public:
int N;
int MOD=1e9+7;
int t[101][101][101];
int solve(int i,int pro,int people,int minProfit,vector<int>& group, vector<int>& profit){
    if(people>N)return 0;
    if(i==group.size()){
        if(pro>=minProfit)return 1;
        return 0;
    }
    if(t[i][pro][people]!=-1)return t[i][pro][people];
    long long not_taken=solve(i+1,pro,people,minProfit,group,profit);
    long long taken= solve(i+1,min(pro+profit[i],minProfit),(people+group[i]),minProfit,group,profit);
    return  t[i][pro][people]=(not_taken +taken)%MOD;

}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N=n;
        memset(t,-1,sizeof(t));
        return solve(0,0,0,minProfit,group,profit);
    }
};