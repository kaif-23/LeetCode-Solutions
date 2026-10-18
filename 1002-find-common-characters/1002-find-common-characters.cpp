class Solution {
public:
vector<int> count( const string& str){
   vector<int>freq(26,0);
   for( char c:str){
    freq[c-'a']++;
   }
   return freq;
}
vector<int> intersection( const vector<int>&freq, const vector<int>&freq2){
    vector<int>t(26,0);
    for(int i=0; i<26;i++){
        t[i]=min(freq[i],freq2[i]);
    }
    return t;
}
    vector<string> commonChars(vector<string>& words) {
        vector<int>last=count(words[0]);
        for(int i=1; i<words.size();i++){
            last=intersection(last,count(words[i]));
        }
        vector<string>result;
        for(int i=0; i<26;i++){
            while(last[i]>0){
                result.push_back(string(1,'a'+i));
                last[i]--;
            }
        }
        return result;
    }
};