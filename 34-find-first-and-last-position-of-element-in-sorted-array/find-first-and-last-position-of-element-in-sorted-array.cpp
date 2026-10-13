class Solution {
public:
    int findFirstPos(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int firstIdx = -1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) {
                firstIdx = mid;
                hi = mid - 1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return firstIdx;
    }
    int findLastPos(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int lastIdx = -1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) {
                lastIdx = mid;
                lo = mid + 1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return lastIdx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return {-1, -1};
        }

        int first = findFirstPos(nums, target);

        if(first == -1) {
            return {-1, -1};
        }

        int last = findLastPos(nums, target);

        return {first, last};
    }
};