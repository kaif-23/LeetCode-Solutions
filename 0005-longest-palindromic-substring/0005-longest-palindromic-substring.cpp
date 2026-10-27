class Solution {
public:


  bool isPal(string &s,int low,int high){
    while(low<high){
        if(s[low]!=s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
  }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1;
        int start=0;
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                if(isPal(s,i,j)&&(j-i+1)>maxLen){
                    start=i;
                    maxLen=j-i+1;
                }
            }
        }
        return s.substr(start,maxLen);
    
    }
};