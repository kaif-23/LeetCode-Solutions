class Solution {
public:
int t[101];
    int solve(int i, string s) {
        if (i == s.length()) {
            return 1;
        }
        if(s[i]=='0')return 0;
        if(t[i]!=-1)return t[i];
        int ans = solve(i + 1, s);
        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                 ans += solve(i + 2, s);
            }
        }
        return  t[i]=ans;
    }
    int numDecodings(string s) { 
        memset(t,-1,sizeof(t));
        return solve(0, s); }
};