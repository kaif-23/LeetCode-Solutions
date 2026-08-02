class Solution {
public:
int m,n,x;
int t[101][101][201];
bool solve(string &s1, string &s2, string &s3, int i,int j ,int k){
    if(i==m && j==n && k==x)return true;
    if(k==x)return false;
    bool res=false;
    if(t[i][j][k]!=-1)return t[i][j][k];
    if(s3[k]==s1[i]){
       res=solve(s1,s2,s3,i+1,j,k+1);
    }
    if(res==true)return t[i][j][k]=true;
    if(s3[k]==s2[j]){
        res=solve(s1,s2,s3,i,j+1,k+1);
    }
    return t[i][j][k]=res;
}
    bool isInterleave(string s1, string s2, string s3) {
         m=s1.length();
         n=s2.length();
         x=s3.length();
         memset(t,-1,sizeof(t));
        return solve(s1,s2,s3,0,0,0);
    }
};