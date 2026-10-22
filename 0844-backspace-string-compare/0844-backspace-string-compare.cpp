class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sr = "";
        string tr = "";
        
        // Process string s
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!sr.empty()) {
                    sr.pop_back();
                }
            } else {
                sr.push_back(s[i]);
            }
        }
        
        // Process string t
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!tr.empty()) {
                    tr.pop_back();
                }
            } else {
                tr.push_back(t[i]);
            }
        }
        
        return sr == tr;
    }
};
