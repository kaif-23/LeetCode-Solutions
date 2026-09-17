class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i = 0, j = 0;

        int currSum = 0;
        int res = INT_MAX;
        int bestMinL = INT_MAX;
        vector<int> minLenTillIdx(n, INT_MAX);

        while (j < n) {
            currSum += arr[j];
            while (i<j && currSum > target) {
                currSum -= arr[i++];
            }
            if (currSum == target) {
                int len = j - i + 1;
                if (i > 0 && minLenTillIdx[i-1] != INT_MAX) {
                    res = min(res, len + minLenTillIdx[i-1]);
                }
                bestMinL = min(len, bestMinL);
            }
            minLenTillIdx[j] = bestMinL;
            j++;
        }
        return res != INT_MAX ? res : -1;
    }
};