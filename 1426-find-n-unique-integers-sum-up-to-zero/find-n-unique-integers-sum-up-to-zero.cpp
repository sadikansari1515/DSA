class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n);
        if(n%2!=0) n--;
        int a = 1;
        for(int i=0; i<n; i+=2) {
            v[i] = a;
            v[i+1] = -a;
            a++;
        }
        return v;
    }
};