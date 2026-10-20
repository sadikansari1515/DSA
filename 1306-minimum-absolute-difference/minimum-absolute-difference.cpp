
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> v;
        int minDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];

            if (diff < minDiff) {
                minDiff = diff;
                v.clear();
                v.push_back({arr[i - 1], arr[i]});
            }
            else if (diff == minDiff) {
                v.push_back({arr[i - 1], arr[i]});
            }
        }

        return v;
    }
};
