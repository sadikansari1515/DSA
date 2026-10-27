class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsei(heights.size(),heights.size());
        vector<int> psei(heights.size(),-1);
        stack<int> s;
        // next smallest element index
        for(int i=0; i<heights.size(); i++) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }
                int idx = s.top();

                if(heights[i] < heights[idx]) {
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
        // previous smallest element index
        for(int i=heights.size()-1; i>=0; i--) {
            while(true) {
                if(s.empty()) {
                    s.push(i);
                    break;
                }
                int idx = s.top();

                if(heights[i] < heights[idx]) {
                    psei[idx] = i;
                    s.pop();
                } 
                else {
                    s.push(i);
                    break;
                }
            }
        }
        int maxA = 0;
        for(int i=0; i<heights.size(); i++) {
            maxA = max(maxA, heights[i]*(nsei[i] - psei[i] -1));
        }
        return maxA;
    }
};