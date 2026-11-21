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
class BSTIterator {
public:
    vector<int> v;
    int index = -1;
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }

    void inorderTraversal(TreeNode* root) {
        if(root == nullptr) return;

        inorderTraversal(root->left);

        v.push_back(root->val);

        inorderTraversal(root->right);
    }
    
    int next() {
        index++;
        return v[index];
    }
    
    bool hasNext() {

     return index + 1 < v.size();   
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */