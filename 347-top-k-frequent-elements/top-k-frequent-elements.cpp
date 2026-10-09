class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Create frequency buckets
        int n = nums.size();
        vector<vector<int>> list(n + 1);

        for (auto& p : mp) {
            int num = p.first;
            int freq = p.second;
            list[freq].push_back(num);
        }

        // Collect k most frequent elements
        vector<int> res;

        for (int i = n; i >= 1; i--) {
            for (int num : list[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};