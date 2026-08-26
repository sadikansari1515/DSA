class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target){
        unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
        int lookupNumber = target - arr[i];

        if (mp.find(lookupNumber) != mp.end()) {
            return {i, mp[lookupNumber]};
        }

        mp[arr[i]] = i;
    }

    return {-1, -1}; 
    }
};