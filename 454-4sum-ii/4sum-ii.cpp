class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for(int a: nums1) {
            for(int b: nums2) {
                int sum = a+b;
                mp[sum]++;
            }
        }

        int count = 0;

        for (int c : nums3) {
            for (int d : nums4) {
                int key = -(c + d);

                if (mp.find(key) != mp.end()) {
                    count += mp[key];
                }
            }
        }
        return count;
    }
};