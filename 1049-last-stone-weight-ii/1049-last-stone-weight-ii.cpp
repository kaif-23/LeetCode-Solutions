class Solution {
public:
int t[30][3001];
int solve(int i,int target,vector<int>&stones){
    if(i==0){
        if(stones[0]<=target){
            return t[i][target]= stones[0];
        }
        return 0;
    }
    if(t[i][target]!=-1)return t[i][target];
    int notTake=solve(i-1,target,stones);
    int take=0;
    if(stones[i]<=target){
        take=stones[i]+solve(i-1,target-stones[i],stones);
    }
    return t[i][target]= max(take,notTake);
}
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        memset(t,-1,sizeof(t));
        int total=accumulate(stones.begin(),stones.end(),0);
        int target=total/2;
        int s1=solve(n-1,target,stones);
        return total-2*s1;
    }
};