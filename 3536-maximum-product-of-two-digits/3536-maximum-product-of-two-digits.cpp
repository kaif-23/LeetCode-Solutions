class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int size=s.length();
        int maxelement=(s[size-1]-'0');
        int maxSecelement=(s[size-2]-'0');
        return maxelement*maxSecelement;


    }
};