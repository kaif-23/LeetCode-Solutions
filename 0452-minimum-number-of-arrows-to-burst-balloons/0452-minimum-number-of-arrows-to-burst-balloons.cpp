class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(begin(points),end(points));
        int arrow=1;
        int i=0,j=1;
        while(j<n){
            int cs=points[i][0];
            int ce=points[i][1];
            int ns=points[j][0];
            int ne=points[j][1];
            if(ce>=ns){
                points[j][0]=max(cs,ns);
                points[j][1]=min(ce,ne);
                i=j;
            }else{
                arrow++;
                i=j;
            }
            j++;
        }
        return arrow;

    }
};