class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>temp(m,vector<int>(n,0));
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                int idx=((i*n+j)+k)%(m*n);
                int new_r=(idx/n);
                int new_c=(idx%n);
                temp[new_r][new_c]=grid[i][j];
            }
        }
        return temp;
    }
};