class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;

        s.push(0);
        for(int i=1; i<nums2.size(); i++) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }

                int idx = s.top();
                if(nums2[i] > nums2[idx]) {
                    mp[nums2[idx]] = nums2[i];
                    s.pop();
                } else {
                    s.push(i);
                    break;
                }
            }
        }
        vector<int> v;
        for(int i=0; i<nums1.size(); i++) {
            if(mp.count(nums1[i])) {
                v.push_back(mp[nums1[i]]);
            } else {
                v.push_back(-1);
            }
        }
        return v;
    }
};