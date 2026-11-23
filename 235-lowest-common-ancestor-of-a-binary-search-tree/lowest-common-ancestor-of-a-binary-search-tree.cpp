class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;

        TreeNode* curr = root;

        while(curr != nullptr) {
            if(pVal > curr->val && qVal > curr->val) {
                curr = curr->right;
            } else if(pVal < curr->val && qVal < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }
        return nullptr;
    }
};