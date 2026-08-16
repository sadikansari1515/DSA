class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i<n && j<n) {
            if(nums[i]==0 && nums[j]!=0) {
                if(j>i) swap(nums[i],nums[j]);
                else j++;
            }
            else if(nums[i]!=0) i++;
            else if(nums[j]==0) j++;
        }
    }
};