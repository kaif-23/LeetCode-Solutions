class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        stringstream ss(s);
        vector<string>words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
         if(pattern.length()!= words.size()) return false;
         for(int i=0; i<pattern.length();i++){
            char a=pattern[i];
            string curr_word=words[i];
            if(mp1.count(a) && mp1[a]!=words[i]) return false;
            if(mp2.count(curr_word) && mp2[curr_word]!=a) return false;
            mp1[a]=words[i];
            mp2[curr_word]=a;
         }
         return true;
        

    }
};