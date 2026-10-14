class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        int lo = 1;
        int hi = x;

        int result = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            long long sqrt = (long)mid*mid;
            if(sqrt == x) {
                return mid;
            }
            else if(sqrt < x) {
                result = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return result;
    }
};