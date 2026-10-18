class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1;
        int hi = num/2;
        if(num == 1) return true;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            long square = (long)mid*mid;
            if(square == num) {
                return true;
            }
            else if(square < num) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};