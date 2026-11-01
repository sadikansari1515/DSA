class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nsei(arr.size(), arr.size());
        vector<int> psei(arr.size(), -1);
        vector<int> ngei(arr.size(), arr.size());
        vector<int> pgei(arr.size(), -1);
        
        stack<int> s;

        //nsei
        for(int i=0; i<arr.size(); i++) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }

                int idx = s.top();

                if(arr[i] < arr[idx]) {
                    nsei[idx] = i;
                    s.pop();
                }
                else {
                    s.push(i);
                    break;
                }
            }
        }

        s = stack<int>();

        // psei
        for(int i=arr.size()-1; i>=0; i--) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }

                int idx = s.top();

                if(arr[i] <= arr[idx]) {
                    psei[idx] = i;
                    s.pop();
                }
                else {
                    s.push(i);
                    break;
                }
            }
        }

        s = stack<int>();

        //ngei
        for(int i=0; i<arr.size(); i++) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }

                int idx = s.top();

                if(arr[i] > arr[idx]) {
                    ngei[idx] = i;
                    s.pop();
                }
                else {
                    s.push(i);
                    break;
                }
            }
        }

        s = stack<int>();

        // pgei
        for(int i=arr.size()-1; i>=0; i--) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }

                int idx = s.top();

                if(arr[i] >= arr[idx]) {
                    pgei[idx] = i;
                    s.pop();
                }
                else {
                    s.push(i);
                    break;
                }
            }
        }

        long res = 0;

        for(int i=0; i<arr.size(); i++) {
            long minContrib = (long)(i - psei[i])*(nsei[i] - i)*arr[i];
            long maxContrib = (long)(i - pgei[i])*(ngei[i] - i)*arr[i];
            res = res + (maxContrib - minContrib);
        }

        return res;
    }
};