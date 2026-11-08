class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            mp[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }

            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto &it : mp) {
            auto &v = it.second;

            sort(v.begin(), v.end());

            vector<int> temp;

            for (auto &p : v) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};