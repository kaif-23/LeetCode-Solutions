class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto lambda=[](vector<int>&vec1,vector<int>&vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        int count = 0;
        int maxEnd = -1;

        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;

    }
};