class Solution {
public:
bool solve(vector<int>& position,int mid,int m){
    int cnt=1; int initP=position[0];
    for(int x :position){
        if(x-initP>=mid){
            cnt++;
            initP=x;
        }
    }
    return cnt>=m ? true:false;
}
    int maxDistance(vector<int>& position, int m) {
       sort(position.begin(),position.end());
       int n=position.size();
       int l=1;
       int r=position[n-1]-position[0];
       int ans=-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(solve(position,mid,m)){
          ans=mid;
          l=mid+1;
        }else{
            r=mid-1;
        }
       }
       return ans;
    }
};