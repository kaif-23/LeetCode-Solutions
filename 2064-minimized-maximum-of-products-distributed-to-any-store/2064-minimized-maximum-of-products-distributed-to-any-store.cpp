class Solution {
public:
bool isPossible(vector<int>& quantities,int n, int mid){
    for(int num:quantities){
        n-=ceil(double(num)/mid);//(num+mid-1)/mid;
        if(n<0){
            return false;
        }
    }
    return true;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1;
        int right=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(quantities,n,mid)){
                right=mid-1;
                ans=mid;
            }else{
                left=mid+1;
            }
        }  
        return ans;
    }
};