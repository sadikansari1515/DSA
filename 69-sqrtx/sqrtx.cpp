class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        int lo = 1;
        int hi = x;
        // T: O(logn) S: O(1)
        int result = -1;

        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            long sqrt = (long)mid*mid;
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