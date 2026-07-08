class Solution {
public:
const int MOD=1e9+7;
typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int>nonZeroCount(n,0);
        vector<ll>numberUpto(n,0);
        vector<ll>digitSumupto(n,0);
        vector<ll>pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%MOD;
        }
        nonZeroCount[0]=(s[0]!='0')?1:0;
        for(int i=1; i<n;i++){
            int digit=s[i]-'0';
            nonZeroCount[i]=nonZeroCount[i-1]+((digit!=0)?1:0);
        }
        numberUpto[0]=s[0]-'0';
        for(int i=1; i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberUpto[i]=((numberUpto[i-1]*10)+digit)%MOD;
            }else{
                numberUpto[i]=numberUpto[i-1];
            }
        }
        digitSumupto[0]=s[0]-'0';
        for(int i=1; i<n;i++){
            int digit=s[i]-'0';
            digitSumupto[i]=digitSumupto[i-1]+digit;
        }
        int q=queries.size();
        vector<int>res(q);
        for(int i=0; i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ll sum=digitSumupto[r]-((l==0)?0:digitSumupto[l-1]);
            int numbefore=(l==0)?0:numberUpto[l-1];
            int k=nonZeroCount[r]-((l==0)? 0:nonZeroCount[l-1]);
            ll x=(numberUpto[r]-(numbefore*pow10[k]%MOD)+MOD)%MOD;
            res[i]=(int)((x*sum)%MOD);
        }

return res;
    }
};