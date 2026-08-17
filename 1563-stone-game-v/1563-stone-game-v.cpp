class Solution {
public:
int t[501][501];
    int solve(int l, int r, vector<int>& prefixSum) {
        if (l >= r)
            return 0;
        if(t[l][r]!=-1)return t[l][r];
        int score = 0;
        for (int mid = l; mid <= r - 1; mid++) {
            int l_Sum = prefixSum[mid] - (l - 1 >= 0 ? prefixSum[l - 1] : 0);
            int r_Sum = prefixSum[r] - prefixSum[mid];
            if (l_Sum < r_Sum) {
                score = max(score, l_Sum + solve(l, mid, prefixSum));
            } else if (r_Sum < l_Sum) {
                score = max(score, r_Sum + solve(mid + 1, r, prefixSum));
            } else {
                score = max({score, l_Sum + solve(l, mid, prefixSum),
                             r_Sum + solve(mid + 1, r, prefixSum)});
            }
        }
        return t[l][r]=score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefixSum(n, 0);
        memset(t,-1,sizeof(t));
        prefixSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
        }
        return solve(0, n-1, prefixSum);
    }
};