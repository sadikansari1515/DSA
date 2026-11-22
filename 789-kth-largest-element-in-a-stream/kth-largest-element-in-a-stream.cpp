
class BSTNode {
public:
    int val;
    int count;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int x) {
        val = x;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};

class KthLargest {
public:
    BSTNode* root;
    int kVal;

    KthLargest(int k, vector<int>& nums) {
        root = nullptr;
        kVal = k;

        for (int num : nums) {
            insertInBST(num);
        }
    }

    void insertInBST(int val) {
        if (root == nullptr) {
            root = new BSTNode(val);
            return;
        }

        BSTNode* curr = root;
        BSTNode* node = new BSTNode(val);

        while (true) {
            curr->count++;

            if (val > curr->val) {
                if (curr->right == nullptr) {
                    curr->right = node;
                    return;
                }
                curr = curr->right;
            }
            else {
                if (curr->left == nullptr) {
                    curr->left = node;
                    return;
                }
                curr = curr->left;
            }
        }
    }

    int search() {
        int kT = kVal;
        BSTNode* curr = root;

        while (curr != nullptr) {
            int rC = curr->right != nullptr
                ? curr->right->count : 0;

            if (kT == rC + 1) {
                return curr->val;
            }
            else if (kT <= rC) {
                curr = curr->right;
            }
            else {
                kT = kT - rC - 1;
                curr = curr->left;
            }
        }

        return -1;
    }

    int add(int val) {
        insertInBST(val);
        return search();
    }
};
