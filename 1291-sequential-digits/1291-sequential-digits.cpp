class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowSize = floor(log10(low)) + 1;
        int highSize = floor(log10(high)) + 1;

        string num = "123456789";
        vector<int> ans;

        for (int len = lowSize; len <= highSize; len++) {
            for (int start = 0; start + len <= 9; start++) {
                string curr = num.substr(start, len);
                int curr_num = stoi(curr);

                if (curr_num >= low && curr_num <= high)
                    ans.push_back(curr_num);
            }
        }

        return ans;
    }
};