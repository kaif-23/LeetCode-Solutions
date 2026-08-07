class Solution {
public:
  int solve(int num){
    int temp;
    int prod=1;
    while(num){
       int temp=num;
        temp=temp%10;
prod*=temp;
        num/=10;
    }
    return prod;
  }
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+10;i++){
            if(solve(i)%t==0)return i;
        }
        return 0;
    }
};