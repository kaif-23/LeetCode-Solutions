class Solution {
public:
    int reverseDegree(string s) {
        int degree=0;
        int n=s.length();
        for(int i=0; i<n;i++){
            degree=degree+((i+1)*(26-(s[i]-'a')));
        }
        return degree;
    }
};