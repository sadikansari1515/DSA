class Solution {
public:
    void sortColors(vector<int>& nums) {
        int minIdx = -1;
    // selection sort
        for(int i=0; i<nums.size(); i++) {
            minIdx = i;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j]<nums[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = nums[minIdx];
            nums[minIdx] = nums[i];
            nums[i] = temp;
        }
    }
};