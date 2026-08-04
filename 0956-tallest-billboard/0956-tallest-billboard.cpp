class Solution {
public:
int n;
int t[21][10001];
int solve(vector<int>&rods,int idx,int diff){
    if(idx>=n){
       if(diff==0)return 0;
       return INT_MIN;
    }
    if(t[idx][diff+5000]!=-1)return t[idx][diff+5000];
    int nothing=solve(rods,idx+1,diff);
    int take_l1=rods[idx]+solve(rods,idx+1,diff+rods[idx]);
    int take_l2=rods[idx]+solve(rods,idx+1,diff-rods[idx]);
    return t[idx][diff+5000]=max({nothing,take_l1,take_l2});
}
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        memset(t,-1,sizeof(t));
        return solve(rods,0,0)/2;
    }
};