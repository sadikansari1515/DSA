
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);

        if(root == nullptr) {
            return node;
        }

        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while(curr!=nullptr) {
            if(val < curr->val) {
                prev = curr;
                curr = curr->left;
                if(curr == nullptr) {
                    prev->left = node;
                }
            } else {
                prev = curr;
                curr = curr->right;
                if(curr == nullptr) {
                    prev->right = node;
                }
            }
        }
        return root;
    }
};