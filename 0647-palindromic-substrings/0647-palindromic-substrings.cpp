class Solution {
public:
int t[1001][1001];
    bool isPalindrome(int i, int j, string s) {
        if (i > j) {
            return true;
        }
        if(t[i][j]!=-1)return t[i][j];
        if (s[i] == s[j]) {
           return  t[i][j]= isPalindrome(i + 1, j - 1, s);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        memset(t,-1,sizeof(t));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};