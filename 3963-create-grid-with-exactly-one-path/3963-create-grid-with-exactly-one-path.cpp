class Solution {
public:
    vector<string> createGrid(int m, int n) {
     vector<string> grid;
        string topRow(n,'.');
        grid.push_back(topRow);
        string left=string(n-1,'#')+'.';
        for(int i=1; i<m;i++){
            grid.push_back(left);
        }
        return grid;
    }
};