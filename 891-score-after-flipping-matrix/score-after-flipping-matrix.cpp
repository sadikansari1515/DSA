class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

// making first columns all 1
        for(int i=0; i<rows; i++) {
            if(grid[i][0] == 0) {
                for(int j=0; j<cols; j++) { // flip
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
// flip the colums where noz>noo
        for(int j=0; j<cols; j++) {
            int noo = 0;
            int noz = 0;
            for(int i=0; i<rows; i++) {
                if(grid[i][j] == 0) noz++;
                else noo++;
            }
            if(noz>noo) {
                for(int i=0; i<rows; i++) {
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        int sum = 0;
        for(int i=rows-1; i>=0; i--) {
            int x = 1;
            for(int j=cols-1; j>=0; j--) {
                sum += grid[i][j]*x;
                x *= 2;
            }
        }
        return sum;
    }
};