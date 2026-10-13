class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n + 1);
        t[1] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        for (int i = 2; i <= n; i++) {
            int i2UglyN = t[i2] * 2;
            int i3UglyN = t[i3] * 3;
            int i5UglyN = t[i5] * 5;
            t[i] = min({i2UglyN, i3UglyN, i5UglyN});
            if (t[i] == i2UglyN) {
                i2++;
            }
            if (t[i] == i3UglyN)
                i3++;
            if (t[i] == i5UglyN)
                i5++;
        }
        return t[n];
    }
};