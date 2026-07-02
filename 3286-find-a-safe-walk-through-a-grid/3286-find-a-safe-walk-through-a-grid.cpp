class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // best[r][c] = maximum remaining health when reaching (r,c)
        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<tuple<int, int, int>> q; // row, col, remaining health

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        best[0][0] = startHealth;
        q.push({0, 0, startHealth});

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nh = h - grid[nr][nc];

                    if (nh > 0 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({nr, nc, nh});
                    }
                }
            }
        }

        return false;
    }
};