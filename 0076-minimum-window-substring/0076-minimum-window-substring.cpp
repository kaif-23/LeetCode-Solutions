class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto&c:t){
            mp[c]++;
        }
        int n=s.length();
        int i=0;
        int j=0;
        int requireCount=t.length();
        int minStart=0;
        int minWindowSize=INT_MAX;
        while(j<n){
            char ch_j=s[j];
            if(mp[ch_j]>0){
              requireCount--;
            }
            mp[ch_j]--;
            while(requireCount==0){
                if(minWindowSize>j-i+1){
                    minWindowSize=j-i+1;
                    minStart=i;
                }
                char ch_i=s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0){
                    requireCount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize==INT_MAX ? "":s.substr(minStart,minWindowSize);
    }
};