class Solution {
public:
void solve(int st,int n,int k,vector<int>&temp,vector<vector<int>>&res){
    if(temp.size()==k){
        res.push_back(temp);
    }
    for(int i=st;i<=n;i++){
        temp.push_back(i);
        solve(i+1,n,k,temp,res);
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(1,n,k,temp,res);
        return res;
    }
};