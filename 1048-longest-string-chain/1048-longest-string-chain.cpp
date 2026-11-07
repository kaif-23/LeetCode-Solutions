class Solution {
public:
int t[1001][1001];
bool check(string& a, string& b){
    if(a.length()+1!=b.length())return false;
    int i=0; int j=0;
    int cnt=0;
    while(i<a.length()&& j<b.length()){
        if(a[i]==b[j])i++,j++;
        if(a[i]!=b[j]){j++;cnt++;}
    }
    return cnt==1;
}
int solve(int idx, int prev, vector<string>&words){
    if(idx==words.size())return 0;
    int take=0;
    if(prev!=-1 && t[idx][prev]!=-1)return t[idx][prev];
    if(prev==-1 ||check(words[prev],words[idx])){
        take=1+solve(idx+1,idx,words);
    }
    int notake=solve(idx+1,prev,words);
    if(prev!=-1){
        t[idx][prev]=max(take,notake);
    }
    return max(notake,take);
}
    int longestStrChain(vector<string>& words) {
        memset(t,-1,sizeof(t));
        sort(words.begin(),words.end(),[](string& a,string& b){
            int len1=a.length();
            int len2=b.length();
            return len1<len2;
        });
      return  solve(0,-1,words);
    }
};