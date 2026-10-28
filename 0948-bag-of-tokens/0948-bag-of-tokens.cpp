class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                // Buy the cheapest token
                power -= tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0 && left < right) {
                // Sell the most expensive token
                power += tokens[right--];
                score--;
            }
            else {
                break;
            }
        }

        return maxScore;
    }
};