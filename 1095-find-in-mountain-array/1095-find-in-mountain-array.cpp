/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
int peakIdx( MountainArray &mountainArr){
    int n=mountainArr.length();
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(mountainArr.get(mid)<mountainArr.get(mid+1)){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}
int bs( MountainArray &mountainArr,int l,int r,int target){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mountainArr.get(mid)==target)return mid;
        else if(mountainArr.get(mid)<target){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return -1;
}
int reveresBS( MountainArray &mountainArr,int l,int r,int target){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mountainArr.get(mid)==target)return mid;
        else if(mountainArr.get(mid)<target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return -1;
}
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int idx=peakIdx(mountainArr);
        int ans=bs(mountainArr,0,idx,target);
        if(ans!=-1){
            return ans;
        }
        return reveresBS(mountainArr,idx,n-1,target);
    }
};