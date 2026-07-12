class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;
        int rank = 1;

        for (int x : temp) {
            if (!mp.count(x)) {
                mp[x] = rank++;
            }
        }

        vector<int> res;
        for (int x : arr) {
            res.push_back(mp[x]);
        }

        return res;
    }
};