class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        vector<bool> sus(n);
        for (auto edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> que;
        que.push(k);
        sus[k] = true;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (int& negbr : adj[curr]) {
                indeg[negbr]--;
                if (!sus[negbr]) {
                    sus[negbr] = true;
                    que.push(negbr);
                }
            }
        }
        vector<int> res;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (sus[i] && indeg[i] > 0) {
                flag = true;
                break;
            } if(!sus[i]) {
                res.push_back(i);
            }
        }
        if (flag) {
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                vec.push_back(i);
                
            }
            return vec;
        }
        return res;
    }
};