class Solution {
public:
    int k = 0;
    int ans = 0;

    void inorder(TreeNode* root, int target) {
        if(!root) return;

        inorder(root->left, target);

        k++;

        if(k == target) {
            ans = root->val;
            return;
        }

        inorder(root->right, target);
    }

    int kthSmallest(TreeNode* root, int target) {
        inorder(root, target);
        return ans;
    }
};