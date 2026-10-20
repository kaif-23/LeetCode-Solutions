class Solution {
public:
 bool isPossibleRotation(vector<int>& vec1,vector<int>& vec2,int k){
    vector<int> vec = vec2;
    vec.insert(vec.end(), vec2.begin(), vec2.end());

    for (int left = 0; left < k; left++) {
        int j = 0;

        while (j < k && vec[left + j] == vec1[j]) {
            j++;
        }

        if (j == k) return true;
    }

    return false;
 }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        int res=0;
        for(int k=1; k<=n;k++){
            if(n%k!=0)continue;
            bool valid=true;
            for(int start=0;start<n;start+=k){
                vector<int>vec1(nums.begin()+start,nums.begin()+start+k);
                vector<int>vec2(sorted.begin()+start,sorted.begin()+start+k);
           
               if(!isPossibleRotation(vec1,vec2,k)){
                  valid =false;
                  break;
               }
            }
            if(valid){
                res+=k;
            }
        }
        return res;

    }
};