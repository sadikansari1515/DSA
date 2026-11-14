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
    bool result;
    void helper(TreeNode* root, int targetSum, int sum) {
        if(root == nullptr) return;

        if(result) return;

        sum = sum + root->val;

        if(root->right == nullptr && root->left == nullptr) {
            if(sum == targetSum) {
                result = true;
            }
            return;
        }

        helper(root->left, targetSum, sum);
        helper(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        result = false;

        helper(root, targetSum, 0);
        return result;
    }
};