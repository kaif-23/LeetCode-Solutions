class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course); // prereq → course
            indegree[course]++;
        }

        queue<int> q;
        vector<int>res;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cnt++;
            res.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
  if (res.size() != numCourses) {
            return {};  // cycle exists
        }
        return res;
    }
};