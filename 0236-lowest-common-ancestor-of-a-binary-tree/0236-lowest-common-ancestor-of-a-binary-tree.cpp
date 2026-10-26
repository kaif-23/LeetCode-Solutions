/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root->val==p->val||root->val==q->val){
            return root;
        }
        TreeNode* lLCA=lowestCommonAncestor(root->left,p,q);
        TreeNode* rLCA=lowestCommonAncestor(root->right,p,q);
        if(lLCA&&rLCA){
            return root;
        }else if(lLCA!=NULL){
            return lLCA;
        }else{
            return rLCA;
        }
    }
};