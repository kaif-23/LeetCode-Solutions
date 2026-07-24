class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string>st;
        int x=0;
        int y=0;
        string key=to_string(x)+"_"+to_string(y);
        st.insert(key);
        for(auto& c:path){
           if(c=='E') x++;
           else if(c=='W')x--;
           else if(c=='N')y++;
           else y--;
           key=to_string(x)+"_"+to_string(y);
           if(st.find(key)!=st.end())return true;
           st.insert(key);
        }
        return false;
    }
};