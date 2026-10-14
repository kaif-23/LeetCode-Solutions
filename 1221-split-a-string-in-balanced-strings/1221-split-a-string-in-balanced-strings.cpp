class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt=0;
        int flag=0;
        for(int i=0; i<s.length();i++){
            if(s[i]=='R')flag-=1;
            else flag+=1;
            if(flag==0)cnt++;
        }
        return cnt;
    }
};