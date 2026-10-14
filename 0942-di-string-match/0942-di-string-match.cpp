class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int>prem(n+1);
        int i=0;
        int j=n;
        int k=0;
        while(i<j && k<n){
          if(s[k]=='I'){
            prem[k++]=i;
            i++;
          }else{
            prem[k++]=j;
            j--;
          }
        }
        if(s.back()=='D')prem[n]=j;
        else prem[n]=i;
        return prem;
    }
};