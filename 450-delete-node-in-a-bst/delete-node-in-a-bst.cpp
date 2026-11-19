
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        while(curr != nullptr && curr->val != key) {
            parent = curr;
            if(key < curr->val) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        if(curr == nullptr) {
            return root;
        }

        if(curr->left != nullptr && curr->right != nullptr) {
            TreeNode* successor = curr->right;
            TreeNode* successorParent = curr;

            while(successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            curr->val = successor->val;
            curr = successor;

            parent = successorParent; 
        }

        if(curr->left == nullptr && curr->right == nullptr) {
            if(parent == nullptr) {
                return nullptr;
            }

            if(curr == parent->right) {
                parent->right = nullptr;
            } else {
                parent->left = nullptr;
            }
        } else if(curr->left == nullptr || curr->right == nullptr) {
            if(parent == nullptr) {
                return curr->left != nullptr ? curr->left : curr->right;
            }
            if(curr == parent->right) {
                parent->right = curr->left != nullptr ? curr->left : curr->right;
            } else {
                parent->left = curr->left != nullptr ? curr->left : curr->right;
            }
        }
        return root;
    }
};