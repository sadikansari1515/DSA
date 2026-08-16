class Solution {
public:
    int minimumSum(int num) {
        // 2932
        int ones = num%10; // 2
        num /=10; // 293
        int tens = num%10; // 3
        num /= 10; // 29
        int hund = num%10; // 9
        num /= 10; // 2
        int thous = num%10; // 2
        vector<int> v(4);
        v[0] = ones;
        v[1] = tens;
        v[2] = hund;
        v[3] = thous;

        sort(v.begin(),v.end());

        int new1 = v[0];
        new1 *= 10;
        new1 += v[2];
        int new2 = v[1];
        new2 *= 10;
        new2 += v[3];

        return new1+new2;
    }
};