class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int r=0;
        int ans=1;
        unordered_map<char,int>mp;
        while(r<s.length()){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;

            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};