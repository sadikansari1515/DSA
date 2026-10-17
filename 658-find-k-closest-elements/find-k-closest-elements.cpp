class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if(k == arr.size()) {
            for(int num: arr) {
                res.push_back(num);
            }
            return res;
        }

        int lo = 0;
        int hi = arr.size()-1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;

            if(arr[mid] >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int i = 0;
        lo = hi - 1;
        while(i < k) {
            if(lo == -1) {
                hi++;
            } else if(hi == arr.size()) {
                lo--;
            } else if(abs(arr[hi]-x) < abs(arr[lo]-x)) {
                hi++;
            } else {
                lo--;
            }
            i++;
        }
        for(int j = lo+1; j<hi; j++) {
            res.push_back(arr[j]);
        }
        return res;
    }
};