class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxDigitCnt=0;
        int maxDigitFreq=0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int sum = 0;
            while (num) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }
            mp[sum]++;
            maxDigitCnt=max(maxDigitCnt,mp[sum]);
        }

        for (auto& it : mp) {
            if(it.second==maxDigitCnt){
                maxDigitFreq++;
            }
        }
        return maxDigitFreq;
    }
};