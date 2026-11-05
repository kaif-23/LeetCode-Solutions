class TreeAncestor {
public:
int rows;
int cols;
vector<vector<int>>upTable;
    TreeAncestor(int n, vector<int>& parent) {
        rows=n;
        cols=log2(n)+1;
        upTable.resize(rows,vector<int>(cols,-1));
        for(int i=0; i<rows;i++){
            upTable[i][0]=parent[i];
        }
        for(int j=1;j<cols;j++){
            for(int node=0; node<rows;node++){
                if(upTable[node][j-1]!=-1){
                    upTable[node][j]=upTable[upTable[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0; j<cols;j++){
            if(k&(1<<j)){
              node=upTable[node][j];
            }
            if(node==-1){
                return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */