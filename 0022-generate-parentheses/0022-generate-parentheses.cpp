class Solution {
public:
vector<string>res;
void solve(int n, string &s,int open,int close){
    if(s.length()==2*n){
        res.push_back(s);
    }
    if(open<n){
        s.push_back('(');
        solve(n,s,open+1,close);
        s.pop_back();
    }
    if(close<open){
        s.push_back(')');
        solve(n,s,open,close+1);
        s.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(n,curr,0,0);
        return res;

    }
};