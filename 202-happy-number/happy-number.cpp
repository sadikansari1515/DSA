class Solution {
public:
    int sumOfSquaresOfDigit(int n) {
        int sum = 0;
        while(n != 0) {
            int digit = n % 10;
            n = n/10;
            sum += (digit*digit);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(true) {
            slow = sumOfSquaresOfDigit(slow);
            fast = sumOfSquaresOfDigit(sumOfSquaresOfDigit(fast));

            if(fast == 1) {
                return true;
            }

            if(fast == slow) {
                return false;
            }
        }
    }
};