class Solution {
public:
int MOD=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                       int k) {
        vector < pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({efficiency[i], speed[i]});
        }
        sort(temp.begin(), temp.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.first > b.first;
             });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sumSpeed = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int e = temp[i].first;
            int s = temp[i].second;
            pq.push(s);
            sumSpeed+=s;
            if(pq.size()>k){
                sumSpeed-=pq.top();
                pq.pop();
            }
            ans=max(ans,sumSpeed*e);
        }
        return ans%MOD;
    }
};