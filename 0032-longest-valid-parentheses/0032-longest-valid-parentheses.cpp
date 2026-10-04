class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int res=0;
        for(auto ch:s){
            if(ch=='('){
                open++;
            }else close++;
            if(open==close){
                res=max(res,open+close);
            }else if(close>open){
                open=close=0;
            }
        }
        close=open=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            if(ch=='('){
                open++;
            }else close++;
            if(open==close){
                res=max(res,open+close);
            }else if(open>close){
                open=close=0;
            }
        }

        return res;
    }
};