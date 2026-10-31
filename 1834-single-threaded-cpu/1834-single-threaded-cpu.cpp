class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedTask;
        for(int i=0; i<n;i++){
            int stTime=tasks[i][0];
            int pTime=tasks[i][1];
            sortedTask.push_back({stTime,pTime,i});
        }
        sort(sortedTask.begin(),sortedTask.end());
        vector<int>order;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long currTime=0;
        int idx=0;
        while(!pq.empty()|| idx<n){
            if(pq.empty() && currTime<sortedTask[idx][0]){
                currTime=sortedTask[idx][0];
            }
            while(idx<n && sortedTask[idx][0]<=currTime){
                pq.push({sortedTask[idx][1],sortedTask[idx][2]});
                idx++;
            }
            auto [processTime,index]=pq.top();
            pq.pop();
            currTime+=processTime;
            order.push_back(index);
        }
        return order;
    }
};