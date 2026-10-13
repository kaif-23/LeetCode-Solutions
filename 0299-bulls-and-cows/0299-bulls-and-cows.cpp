class Solution {
public:
    string getHint(string secret, string guess) {
        int A=0; int B=0;
        int n=secret.length();
        vector<int>number(10);
        for(int i=0; i<n;i++){
            int s=secret[i]-'0';
            int g=guess[i]-'0';
            if(s==g)A++;
            else {
                if(number[s]<0)B++;
                if(number[g]>0)B++;
                number[s]++;
                number[g]--;
            }
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};