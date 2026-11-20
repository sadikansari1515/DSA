
class Solution {
public:
    long long last = LLONG_MIN;
    bool isValidBSTHelper(TreeNode* root) {
        if(root == nullptr) return true;

        bool left = isValidBSTHelper(root->left);
        if(!left) return false;

        if(last != LLONG_MIN && root->val <= last) {
            return false;
        }
        last = root->val;

        bool right = isValidBSTHelper(root->right);
        return right;
    }
    bool isValidBST(TreeNode* root) {
        
        return isValidBSTHelper(root);
    }
};