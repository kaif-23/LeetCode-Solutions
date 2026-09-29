class Solution {
public:
int n;
pair<int,int>getCord(int num){
    int RT= (num-1)/n;
    int RB=(n-1)-RT;
    int col=(num-1)%n;
    if((n%2==1 && RB%2==1)||(n%2==0 && RB%2==0))col=(n-1)-col;
    return make_pair(RB,col);
}
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        queue<int>que;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[n-1][0]=true;
        que.push(1);
        int steps=0;
        while(!que.empty()){
            int level=que.size();
            while(level--){
                int x=que.front();
                que.pop();
                if(x==n*n){
                    return steps;
                }
                for(int k=1;k<=6;k++){
                    int val=x+k;
                    if(val>n*n) break;
                    pair<int,int> cord=getCord(val);
                    int r=cord.first;
                    int c=cord.second;
                    if(vis[r][c]==true)continue;
                    vis[r][c]=true;
                    if(board[r][c]==-1){
                        que.push(val);
                    }else{
                        que.push(board[r][c]);
                    }
                }
            }
                steps++;
        }
return -1;
    }
};