class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>sortedHeight(heights.begin(),heights.end());
        sort(sortedHeight.begin(),sortedHeight.end());
        int ans=0;
        for(int i=0; i<heights.size();i++){
            if(sortedHeight[i]!=heights[i])ans++;
        }
        return ans;
    }

};