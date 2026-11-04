class Solution {
public:
    multiset<int> small, large;

    void balance() {
        while (small.size() > large.size() + 1) {
            auto it = prev(small.end());
            large.insert(*it);
            small.erase(it);
        }

        while (small.size() < large.size()) {
            auto it = large.begin();
            small.insert(*it);
            large.erase(it);
        }
    }

    void add(int x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
        }
        else {
            large.insert(x);
        }

        balance();
    }

    void remove(int x) {
        auto it = small.find(x);

        if (it != small.end()) {
            small.erase(it);
        }
        else {
            it = large.find(x);
            if (it != large.end())
                large.erase(it);
        }

        balance();
    }

    double getMedian() {
        if (small.size() > large.size())
            return *small.rbegin();

        return ((double)*small.rbegin() + *large.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k)
                remove(nums[i - k]);

            if (i >= k - 1)
                res.push_back(getMedian());
        }

        return res;
    }
};