class Solution {
public:
int result;
pair<int,int> solve(TreeNode* root){
   if(!root){
    return {0,0};
   }
   auto p1=solve(root->left);
   auto p2=solve(root->right);
   int sum=root->val+p1.first +p2.first;
   int cnt=1+p2.second+p1.second;
   int avg=sum/cnt;
   if(avg==root->val)result++;
   return {sum,cnt};
}
    int averageOfSubtree(TreeNode* root) {
        result=0;
        solve(root);
        return result;
    }
};