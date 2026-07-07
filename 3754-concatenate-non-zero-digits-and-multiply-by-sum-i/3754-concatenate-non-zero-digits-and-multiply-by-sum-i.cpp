class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string ans = "";
         if(n==0)return 0;
        while (n > 0) {
            int temp = n % 10;

            if (temp != 0) {
                ans += char(temp + '0');
            }

            sum += temp;
            n /= 10;
        }

        reverse(ans.begin(), ans.end());

        return stoll(ans) * sum;
    }
};