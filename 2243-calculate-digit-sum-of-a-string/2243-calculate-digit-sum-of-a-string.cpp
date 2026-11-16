class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            int cnt = 0;
            string temp = "";
            int sum = 0;
            
            for (int i = 0; i < s.length(); i++) {
                sum += s[i] - '0';
                cnt++;
                
                if (cnt == k) {
                    temp += to_string(sum);
                    cnt = 0;
                    sum = 0; 
                }
            }
            
            if (cnt > 0) {
                temp += to_string(sum);
            }
            
            s = temp;  
        }
        return s;
    }
};
