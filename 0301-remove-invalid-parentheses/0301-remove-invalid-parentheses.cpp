class Solution {
public:
int n;
int maxlen;
unordered_set<string>st;
void solve(string& s,string &curr,int count,int i){
    if(count<0)return;
    if(i==n){
        if(count==0){
            if(curr.length()>maxlen){
                maxlen=curr.length();
                st.clear();
            }
            if(curr.length()==maxlen){
                st.insert(curr);
            }
        }
        return;
    }
    if(s[i]!='('&& s[i]!=')'){
        curr.push_back(s[i]);
        solve(s,curr,count,i+1);
        curr.pop_back();
        return;
    }
    curr.push_back(s[i]);
    solve(s,curr,count+(s[i]=='('?1:-1),i+1);
    curr.pop_back();
    solve(s,curr,count,i+1);
}
    vector<string> removeInvalidParentheses(string s) {
        n=s.length();
        st.clear();
        string curr="";
         maxlen=0;
        solve(s,curr,0,0);
        return vector<string>(st.begin(),st.end());
    }
};