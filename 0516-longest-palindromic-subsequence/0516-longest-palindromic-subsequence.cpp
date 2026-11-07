class Solution {
public:
    int t[1001][1001];
    int solve(string& s, int l, int r) {
        if (l > r)
            return 0;
        if (l == r)
            return 1;
        if (t[l][r] != -1) {
            return t[l][r];
        }

        if (s[l] == s[r]) {
            return t[l][r] = 2 + solve(s, l + 1, r - 1);
        } else {
            return t[l][r] = max(solve(s, l + 1, r), solve(s, l, r - 1));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int cnt = 0;
        memset(t, -1, sizeof(t));

        return solve(s, 0, n-1);
    }
};