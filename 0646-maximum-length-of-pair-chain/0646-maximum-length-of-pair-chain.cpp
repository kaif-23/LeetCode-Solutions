class Solution {
public:
int t[1001][1001];
int solve(int cidx,int pidx,vector<vector<int>>& pairs){
    if(cidx==pairs.size())return 0;
    if(pidx!=-1 && t[cidx][pidx]!=-1)return t[cidx][pidx];
    int take=0;
    if(pidx==-1 ||pairs[cidx][0]>pairs[pidx][1]){
        take=1+solve(cidx+1,cidx,pairs);
    }
    int notake=solve(cidx+1,pidx,pairs);
    if(pidx!=-1){
        t[cidx][pidx]=max(notake,take);
    }
    return max(notake,take);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t,-1, sizeof(t));
       sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
       });
       return solve(0,-1,pairs); 
    }
};