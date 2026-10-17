class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int ans=10;
        int currdigits=9;
        int avaiable=9;
        for(int i=2;i<=n;i++){
            currdigits*=avaiable;
            avaiable--;
            ans+=currdigits;
        }
        return ans;
    }
};