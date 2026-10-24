class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> que;

        // Step 1: push all rotten + count fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh==0)return 0;
        int mint = 0;
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        // Step 2: BFS
        while (!que.empty() ) {
            int size = que.size();

            while (size--) {
                auto [i, j] = que.front();
                que.pop();

                for (auto &d : dir) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                        grid[ni][nj] == 1) {

                        grid[ni][nj] = 2;
                        que.push({ni, nj});
                        fresh--;
                    }
                }
            }

            mint++; // one level = one minute
        }

        // Step 3: result
        return (fresh == 0) ? mint-1 : -1;
    }
};