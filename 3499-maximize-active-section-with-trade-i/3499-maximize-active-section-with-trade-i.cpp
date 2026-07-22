class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int activeCnt=count(s.begin(),s.end(),'1');
        vector<int>zeroCnt;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int st=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zeroCnt.push_back(i-st);
            }else{
                i++;
            }
        }
        int maxPairSum=0;
        for(int i=1;i<zeroCnt.size();i++){
            maxPairSum=max(maxPairSum,zeroCnt[i-1]+zeroCnt[i]);
        }

        return maxPairSum+activeCnt;

    }
};