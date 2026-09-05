class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int k = 10000;
        vector<int> countArr(2*k+1);
        for(int i=0; i<nums.size(); i++) {
            countArr[nums[i]+k]++;
        }

        int maxSum = 0;
        bool isEvenIndex = true;
        for(int i=0; i<2*k+1; i++) {
            while(countArr[i] > 0) {
                maxSum = maxSum + (isEvenIndex ? (i-k) : 0);
                countArr[i]--;
                isEvenIndex = !isEvenIndex;
            }
        }
        return maxSum;
    }
};