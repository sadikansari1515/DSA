class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        int s = 0;
        int d = 0;
        while(s < n) {
            if(arr[s] == 0) {
                if(d < n) {
                    v[d] = 0;
                }
                d++;
                if(d < n) {
                    v[d] = 0;
                }
            }
            else {
                if(d < n) {
                    v[d] = arr[s];
                }
            }
            s++;
            d++;
        }
        for(int i=0; i<n; i++) {
            arr[i] = v[i];
        }
    }
};