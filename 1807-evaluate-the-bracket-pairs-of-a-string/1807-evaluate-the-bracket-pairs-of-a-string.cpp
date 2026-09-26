class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> mp;

        for (auto& v : knowledge) {
            mp[v[0]] = v[1];
        }
        for (int i = 0; i <s.length(); i++) {
            if (s[i] == '(') {
                int j = s.find(')', i);
                string key = s.substr(i + 1, j-i-1);
                if (mp.find(key) != mp.end()) {
                    s.replace(i, j-i+1, mp[key]);
                } else {
                    s.replace(i, j-i+1, "?");
                }
            } 
        }
        return s;
    }
};