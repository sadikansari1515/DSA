class Solution {
public:
    // iterative method
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        q.push(root);

        while(!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();

            if(node1 == nullptr && node2 == nullptr) {
                continue;
            }

            if(node1 == nullptr || node2 == nullptr) {
                return false;
            }

            if(node1->val != node2->val) {
                return false;
            }

            q.push(node1->left);
            q.push(node2->right);

            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};