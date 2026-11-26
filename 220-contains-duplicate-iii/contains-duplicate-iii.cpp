
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        set<long long> st;

        st.insert(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            long long num = nums[i];

            // Find ceiling (smallest element >= num)
            auto it = st.lower_bound(num);

            if (it != st.end() && *it - num <= valueDiff) {
                return true;
            }

            // Find floor (largest element <= num)
            if (it != st.begin()) {
                auto prevIt = prev(it);

                if (num - *prevIt <= valueDiff) {
                    return true;
                }
            }

            // Insert current number
            st.insert(num);

            // Maintain sliding window
            if (i >= indexDiff) {
                st.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};
