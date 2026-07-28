class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        string mid = (n % 2 != 0) ? s.substr(n / 2, 1) : "";

        sort(half.begin(), half.end());

        string rev = half;
        reverse(rev.begin(), rev.end());

        return half +mid+ rev;
    }
};