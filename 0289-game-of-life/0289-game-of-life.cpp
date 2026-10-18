class Solution {
public:
    int m, n;
    int getCnt(int i, int j, vector<vector<int>>& board) {
        int cnt = 0;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int d = 0; d < 8; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (board[x][y] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>>next=board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = getCnt(i, j, board);
                if (board[i][j] == 1) {
                    next[i][j] = (cnt == 2 || cnt == 3) ? 1 : 0;
                } else {
                    next[i][j] = (cnt == 3) ? 1 : 0;
                }
            }
        }
        board=next;
    }
};