
class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };

    int n, m;

    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        for (auto dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                !vis[ni][nj] &&
                board[ni][nj] == 'O') {

                dfs(ni, nj, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First and last rows
        for (int j = 0; j < m; j++) {

            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);

            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis);
        }

        // First and last columns
        for (int i = 0; i < n; i++) {

            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);

            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }

        // Capture surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};