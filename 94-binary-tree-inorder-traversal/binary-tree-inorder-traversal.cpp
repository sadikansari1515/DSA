void helper(TreeNode* root, vector<int>& ans) {
    if(root == nullptr) return;

    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        helper(root, ans);

        return ans;
    }
};