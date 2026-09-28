class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);

            } else if (s[i] == ')') {
                int curr=st.size();
                ans = max(ans, curr);
                st.pop();
            }
        }
        return ans;
    }
}
;