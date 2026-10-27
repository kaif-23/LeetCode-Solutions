class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char ch : p) {
            mp1[ch]++;
        }

        int l = 0;
        int k = p.length();
        vector<int> res;
        for(int r=0; r<s.length();r++){
            mp2[s[r]]++;
            if(r-l+1>k){
                mp2[s[l]]--;
                if(mp2[s[l]]==0){
                    mp2.erase(s[l]);
                    
                }
                l++;
            }
            if(r-l+1==k && mp1==mp2){
                res.push_back(l);
            }
        }
        return res;
    }
};