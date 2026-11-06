class Solution {
public:
 int t[601][101][101];
pair<int,int>getCnt(string str){
    int cnt_0=0;
    int cnt_1=0;
    for(auto ch:str){
        if(ch=='0'){
            cnt_0++;
        }else cnt_1++;
    }
    return {cnt_0,cnt_1};
}
int solve(int i,vector<string>& strs, int m, int n){
    if(i==strs.size()){
        return 0;
    }
    if(t[i][m][n]!=-1)return t[i][m][n];
    auto [cnt_0,cnt_1] =getCnt(strs[i]);
    int take=0,not_Take=0;
    not_Take=solve(i+1,strs,m,n);
    if(cnt_0<=m && cnt_1<=n){
        take=1+solve(i+1,strs,m-cnt_0,n-cnt_1);
    }
    return t[i][m][n]= max(not_Take,take);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t,-1,sizeof(t));
      return   solve(0,strs,m,n);

    }
};