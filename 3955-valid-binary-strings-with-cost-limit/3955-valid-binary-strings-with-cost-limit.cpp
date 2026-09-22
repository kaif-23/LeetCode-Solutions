class Solution {
public:
    void solve(string& curr, int n, int k, vector<string>& res,int cost) {
        if (curr.length() >= n ) {
            res.push_back(curr);
            return;
        }
        int i=curr.length();
        if ((curr.empty() || curr.back() != '1') && cost+i<=k) {
            curr.push_back('1');
            solve(curr, n, k, res,cost+i);
            curr.pop_back();
        }

        curr.push_back('0');
        solve(curr, n, k, res,cost);
        curr.pop_back();
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string curr = "";
        solve(curr, n, k, res,0);

        return res;
    }
};