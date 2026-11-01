class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;  // Max heap of durations

        int time = 0;
        int cnt = 0;

        for (auto& vec : courses) {

            int currTime = vec[0];
            int currDeadline = vec[1];

            if (time + currTime <= currDeadline) {

                time += currTime;
                cnt++;
                pq.push(currTime);

            } else {

                if (!pq.empty() && pq.top() > currTime) {

                    int prev = pq.top();
                    pq.pop();

                    time -= prev;
                    time += currTime;

                    pq.push(currTime);
                }
            }
        }

        return cnt;
    }
};