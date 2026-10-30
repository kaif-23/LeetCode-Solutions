class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
          return a[1]>b[1];   
        });
           
            int ans=0;
            for(auto &vec:boxTypes){
                if(truckSize==0)break;
                int boxesPossible=min(vec[0],truckSize);
                truckSize-=boxesPossible;
                ans+=boxesPossible*vec[1];
                
            }
            return ans;
                
    }
};