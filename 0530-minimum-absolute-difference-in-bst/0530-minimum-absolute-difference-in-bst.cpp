/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int minDiff=INT_MAX;
TreeNode* prev;
void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    if(prev!=NULL){
 minDiff=min(minDiff,root->val-prev->val);
    }
   
    prev=root;
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        prev=NULL;
       inorder(root);
       return minDiff;
    
    }
};