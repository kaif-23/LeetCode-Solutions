class Solution {
public:
 bool bs(vector<int>&num,int target){
    int left=0;
    int right=num.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(num[mid]==target)return true;
        else if(num[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return false;
 }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(auto& num:matrix){
           if(bs(num,target))return true;
        }
        return false;
    }
};