class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        vector<int> v(n);
        int val;
        for(int i=n-1; i>=0; i--) {
            if(abs(nums[l]) > abs(nums[r])) {
                val = nums[l];
                l++;
            }
            else {
                val = nums[r];
                r--;
            }
            v[i] = val*val;
        }
        return v;
    }
};