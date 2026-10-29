class Solution {
public:
bool solve(vector<int>&bloomDay,int mid,int m,int k){
    int total=0;
    int cnt=0;
    for(int x:bloomDay){
        if(x<=mid){
            cnt++;
            if(cnt==k){
                total++;
                cnt=0;
            }
        }else{
            cnt=0;
        }
    }
    return total>=m? true:false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(bloomDay,mid,m,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};