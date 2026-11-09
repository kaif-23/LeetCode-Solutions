
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {
        set<int> freeServers;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> cnt(k, 0);

        for (int i = 0; i < k; i++) {
            freeServers.insert(i);
        }

        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            int st = arrival[i];
            int end = load[i];

            // Release all servers that have finished
            while (!busy.empty() && busy.top().first <= st) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }

            if (freeServers.empty())
                continue;

            int target = i % k;

            auto it = freeServers.lower_bound(target);

            if (it == freeServers.end()) {
                it = freeServers.begin();
            }

            int server = *it;
            freeServers.erase(it);

            cnt[server]++;

            busy.push({st + end, server});
        }

        int maxCnt = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxCnt) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
