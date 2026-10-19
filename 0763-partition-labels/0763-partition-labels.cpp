class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastOccurence(26,-1);
        for(int i=0; i<s.length();i++){
            lastOccurence[s[i]-'a']=i;
        }
        int start=0;
        int i=0;
        int end=0;
        vector<int>res;
        while(i<s.length()){
            end=max(end,lastOccurence[s[i]-'a']);
            if(i==end){
                res.push_back(end-start+1);
                start=end+1;
            }
            i++;
        }
        return res;
    }
};