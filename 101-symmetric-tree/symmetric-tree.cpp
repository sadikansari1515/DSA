class Solution {
public:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;

        if(left == nullptr || right == nullptr) return false;

        if(left->val != right->val) return false;

        return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return isSymmetricHelper(root->left, root->right);
    }
};