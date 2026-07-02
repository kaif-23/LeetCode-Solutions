class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int i=0,j=1;
        int count=0;
        while(j<n){
            vector<int>interval1=intervals[i];
            vector<int>interval2=intervals[j];
            int cs=interval1[0];
            int ce=interval1[1];
            int ns=interval2[0];
            int ne=interval2[1];
            if(ce<=ns){
                i=j;
                j++;
            }else if(ce<=ne){
                 j++;
                 count++;
            }else if(ce>ne){
                i=j;
                j++;
                count++;
            }
        }
        return count;
    }
};