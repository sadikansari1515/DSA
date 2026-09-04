class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minDistance = INT_MAX;
        int left = 0,
            right = 0;
        int runningSum = 0;
        while(right < nums.size()) {
            runningSum += nums[right];
            while(runningSum >= target) {
                minDistance = min(minDistance, right - left + 1);
                runningSum -= nums[left];
                left++;
            }
            right++; 
        }
        return minDistance == INT_MAX ? 0 : minDistance;
    }
};