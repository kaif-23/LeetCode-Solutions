class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>cnt(26,0),vis(26,0);
        string res="";
        for(auto& c:s){
            cnt[c-'a']++;
        }
        for(auto& c:s){
            int idx=c-'a';
            if(!vis[idx]){
                while(!res.empty() && res.back()>c){
                    int top_idx=res.back()-'a';
                    if(cnt[top_idx]>0){
                        vis[top_idx]=0;
                        res.pop_back();
                    }else{
                        break;
                    }
                }
                vis[idx]=1;
                res.push_back(c);
            }
            cnt[idx]--;
        }
        return res;
    }
};