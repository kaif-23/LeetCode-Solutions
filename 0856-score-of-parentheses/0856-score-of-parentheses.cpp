class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        vector<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push_back(ans);
                ans = 0;
            }
            if (s[i] == ')' && s[i - 1] == '(') {
                ans = st.back() + 1;
                st.pop_back();
            } else if (s[i] == ')' && s[i - 1] == ')') {
                ans = st.back() + (2 * ans);
                st.pop_back();
            }
        }
        return ans;
    }
};