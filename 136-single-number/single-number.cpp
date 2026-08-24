class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int res = 0;
        for(int num : arr) {
            res = res ^ num;
        }
        return res;
    }
};