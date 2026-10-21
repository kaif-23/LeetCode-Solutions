class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
bool sorted = is_sorted(s.begin(), s.end());
        if (sorted)
            return 0;
        if (n == 2)
            return -1;
        if (n < 2)
            return 0;
        
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        bool minInPrefix = false;
        bool maxInSuffix = false;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn)
                minInPrefix = true;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == mx)
                maxInSuffix = true;
        }
        if (mn == s[0] || mx == s[n - 1])
            return 1;
        if (minInPrefix || maxInSuffix)
            return 2;

        return 3;
    }
};