class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel;
        int prev = 0;
        int ans = 0;
        for (auto vec : stations) {
            int pos = vec[0];
            int gas = vec[1];
            fuel -= (pos - prev);
            while (fuel < 0) {
                if (pq.empty()) {
                    return -1;
                }
                int prevbest = pq.top(); // best fuel optionshaving greater capaticay avaiblae
                fuel += prevbest;
                pq.pop();
                ans++;
            }
            prev=pos;
            pq.push(gas);
        }
        fuel-=(target-prev);
        while(fuel<0){
            if(pq.empty())return -1;
            fuel+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};