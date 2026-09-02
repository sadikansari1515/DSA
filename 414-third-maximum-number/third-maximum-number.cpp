class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        for(int arr : nums) {
            if(arr == max1 || arr == max2 || arr == max3) {
                continue;
            }

            if(arr > max1) {
                max3 = max2;
                max2 = max1;
                max1 = arr;
            }
            else if(arr > max2) {
                max3 = max2;
                max2 = arr;
            }
            else if(arr > max3) {
                max3 = arr;
            }
        }
        if(max3 == LLONG_MIN) return max1;


        return max3;
    }
};