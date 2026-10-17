class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_set<int>st;
        int sumA=0;
        int sumB=0;
        for(auto num:aliceSizes){
            sumA+=num;
        }
        for(auto num: bobSizes){
            sumB+=num;
            st.insert(num);
        }
        vector<int>ans;
        int finalvalue=(sumA+sumB)/2;
        for(int i=0; i<aliceSizes.size();i++){
            int value=finalvalue+aliceSizes[i]-sumA;
            if(st.count(value)){
              ans.push_back(aliceSizes[i]);
              ans.push_back(value);
              return ans;
            }
        }
        return ans;
    }
};