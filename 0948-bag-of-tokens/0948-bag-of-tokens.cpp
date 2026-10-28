class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int left=0;
        int right=tokens.size()-1;
        int N=tokens.size();
        while(N--){
             if(power>=tokens[left]){
                score+=1;
                power-=tokens[left++];
            }
            else if(N!=0 && score>=1){
                power+=tokens[right--];
                score-=1;
            }
        }
        return score;
    }
};