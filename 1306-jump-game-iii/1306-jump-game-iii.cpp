class Solution {
public:
    bool solve(int i, vector<int>& arr, vector<int>& visited) {
        int n = arr.size();

        if (i < 0 || i >= n)
            return false;

        if (arr[i] == 0)
            return true;

        if (visited[i])
            return false;

        visited[i] = 1;

        bool forward = solve(i + arr[i], arr, visited);
        bool backward = solve(i - arr[i], arr, visited);

        return forward || backward;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int> visited(n, 0);

        return solve(start, arr, visited);
    }
};