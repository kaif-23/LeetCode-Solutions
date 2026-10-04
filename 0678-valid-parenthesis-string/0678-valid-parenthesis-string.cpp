class Solution {
public:

    int t[101][101][101];

    bool solve(string &s, int openCnt, int closeCnt, int i) {

        // Invalid state
        if (closeCnt > openCnt)
            return false;

        // Base case
        if (i >= s.length()) {
            return openCnt == closeCnt;
        }

        // Already calculated
        if (t[i][openCnt][closeCnt] != -1)
            return t[i][openCnt][closeCnt];

        if (s[i] == '*') {

            // '*' -> '('
            bool a = solve(s, openCnt + 1, closeCnt, i + 1);

            // '*' -> ')'
            bool b = solve(s, openCnt, closeCnt + 1, i + 1);

            // '*' -> empty
            bool c = solve(s, openCnt, closeCnt, i + 1);

            return t[i][openCnt][closeCnt] = (a || b || c);
        }

        if (s[i] == '(') {
            return t[i][openCnt][closeCnt] =
                solve(s, openCnt + 1, closeCnt, i + 1);
        }

        // s[i] == ')'
        return t[i][openCnt][closeCnt] =
            solve(s, openCnt, closeCnt + 1, i + 1);
    }

    bool checkValidString(string s) {
        memset(t, -1, sizeof(t));

        return solve(s, 0, 0, 0);
    }
};