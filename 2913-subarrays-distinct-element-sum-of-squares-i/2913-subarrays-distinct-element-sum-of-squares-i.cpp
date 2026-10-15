class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sumC = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            int Cnt = 0;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                Cnt = st.size();
                sumC += Cnt * Cnt;
            }
        }
        return sumC;
    }
};