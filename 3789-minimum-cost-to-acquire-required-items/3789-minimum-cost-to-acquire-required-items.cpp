class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1= 1LL*cost1*need1+1LL*cost2*need2;
        long long ans2=1LL*max(need1,need2)*costBoth;

        long long mult=need1>need2 ?cost1 :cost2;
        long long ans3=1LL*min(need1,need2)*costBoth+1LL*abs(need1-need2)*mult;
        return min({ans1,ans2,ans3});
    }
};