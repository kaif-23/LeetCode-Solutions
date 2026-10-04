class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                minOpen++;
                maxOpen++;
            }

            else if (ch == ')') {
                minOpen--;
                maxOpen--;
            }

            else { // '*'
                minOpen--;  // '*' -> ')'
                maxOpen++;  // '*' -> '('
            }

            // Even the minimum possibility is negative
            if (maxOpen < 0)
                return false;

            // We cannot have negative unmatched '('
            minOpen = max(0, minOpen);
        }

        return minOpen == 0;
    }
};