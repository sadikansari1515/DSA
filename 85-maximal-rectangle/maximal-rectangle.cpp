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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(), vector<int> (matrix[0].size(),0));
        int maxH = 0;

        for(int col=0; col<matrix[0].size(); col++) {
            mat[0][col] = matrix[0][col] == '1' ? 1 : 0;
        }

        maxH = max(maxH, largestRectangleArea(mat[0]));

        for(int row=1; row<matrix.size(); row++) {
            for(int col=0; col<matrix[0].size(); col++) {
                mat[row][col] = matrix[row][col] == '1' ? mat[row-1][col] + 1: 0;
            }
            maxH = max(maxH, largestRectangleArea(mat[row]));
        }
        return maxH;
    }

};