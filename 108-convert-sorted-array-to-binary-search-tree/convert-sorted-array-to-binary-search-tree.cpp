
class Solution {
public:
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }

        int mid = start + (end - start)/2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, end);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = sortedArrayToBSTHelper(nums, 0, nums.size()-1);
        return root;
    }
};