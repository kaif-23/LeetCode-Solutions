class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')')
            return false;

        queue<tuple<int, int, int>> q;

        vector<vector<vector<bool>>> vis(
            m, vector<vector<bool>>(
                n, vector<bool>(m + n, false)
            )
        );

        q.push({0, 0, 1});
        vis[0][0][1] = true;

        vector<vector<int>> directions = {
            {1, 0},  // Down
            {0, 1}   // Right
        };

        while (!q.empty()) {
            auto [x, y, balance] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) {
                if (balance == 0)
                    return true;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= m || ny >= n)
                    continue;

                int newBalance = balance;

                if (grid[nx][ny] == '(')
                    newBalance++;
                else
                    newBalance--;

                if (newBalance < 0)
                    continue;

                if (newBalance > m + n - 1)
                    continue;

                if (!vis[nx][ny][newBalance]) {
                    vis[nx][ny][newBalance] = true;
                    q.push({nx, ny, newBalance});
                }
            }
        }

        return false;
    }
};