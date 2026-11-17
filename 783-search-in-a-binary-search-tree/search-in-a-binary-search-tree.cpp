class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while(curr != nullptr) {
            
            if(curr->val == val) {
                return curr;
            } else if(val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nullptr;
    }
};