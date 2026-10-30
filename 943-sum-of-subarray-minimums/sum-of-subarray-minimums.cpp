class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsei(arr.size(), arr.size());
        vector<int> psei(arr.size(), -1);
        
        stack<int> s;
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
        long sum = 0;
        for(int i=0; i<arr.size(); i++) {
            int leftBoundary = i - psei[i];
            int rightBoundary = nsei[i] - i;

            long contrib = (leftBoundary * rightBoundary) % 1000000007;
            contrib = (contrib * arr[i]) % 1000000007;
            sum = (sum + contrib) % 1000000007;
        }

        return (int) sum;
    }
};