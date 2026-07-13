class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            } else {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();

                if (s == "+")
                    st.push(first + second);
                else if (s == "-")
                    st.push(first - second);
                else if (s == "*")
                    st.push(first * second);
                else
                    st.push(first / second);
            }
        }

        return st.top();
    }
};