class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //prefixSum rowisee
        for(int i=0; i<m;i++){
            for(int j=1; j<n;j++){ //starting from 2nd cols as first remain same
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int cnt=0;
        //fix a point in matrix perform all submatrix from that point of col then next col
        for(int stCol=0;stCol<n;stCol++){
            //curent cols at the point of operations
            for(int currCol=stCol;currCol<n;currCol++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                //basic of subaray of sum equal k 
                for(int row=0; row<m;row++){
                    sum+=matrix[row][currCol]-(stCol>0 ? matrix[row][stCol-1]:0);//for orevius values
                    if(mp.count(sum-target)){
                        cnt+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};