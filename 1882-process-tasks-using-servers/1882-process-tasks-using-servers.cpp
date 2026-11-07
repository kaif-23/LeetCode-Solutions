class Solution {
public:
typedef pair<int,int> P;
typedef tuple<long long,int,int> T;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<P,vector<P>,greater<>>freeserver;
        priority_queue<T,vector<T>,greater<>>busyserver;

        for(int i=0;i<n;i++){
            freeserver.push({servers[i],i});
        }
        
        vector<int>res(m);
        for(int i=0; i<m;i++){
            while(!busyserver.empty() && get<0>(busyserver.top())<=i){
                auto[finTime,wt,idx]=busyserver.top();
                busyserver.pop();
                freeserver.push({wt,idx});
            }
            if(freeserver.empty()){
                 auto[finTime,wt,idx]=busyserver.top();
                 busyserver.pop();
                 res[i]=idx;
                 busyserver.push({finTime+tasks[i],wt,idx});
            }else{
                auto[wt,idx]=freeserver.top();
                freeserver.pop();
                busyserver.push({i+tasks[i],wt,idx});
                res[i]=idx;
            }
        }
        return res;
    }
};