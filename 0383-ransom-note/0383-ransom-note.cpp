class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int>magMap;
       for(char c:magazine){
        magMap[c]++;
       }
       for(char c:ransomNote){
         if(magMap[c]<=0){
            return false;
         }
         magMap[c]--;
       }
       return true;

    }
};