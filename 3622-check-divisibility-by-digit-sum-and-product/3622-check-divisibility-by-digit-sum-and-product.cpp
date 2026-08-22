class Solution {
public:
    bool checkDivisibility(int n) {
        int i = n;
        int sum = 0;
        int prod = 1;
        while (i) {
            int digit = i % 10;
            i /= 10;
            sum += digit;
            prod *= digit;
        }
        return (n % (sum + prod)) == 0;
    }
};