class Solution {
public:
    bool numberHasEvenDigits(int n) {
        int countDigit;
        while(n!=0) {
            n = n/10;
            countDigit++;
        }
        return countDigit%2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(numberHasEvenDigits(nums[i])) {
                evenCount++;
            }
        }
        return evenCount;
    }
};