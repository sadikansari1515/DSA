class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9,vector<int>(9,0));
        vector<vector<int>> cols(9,vector<int>(9,0));
        vector<vector<int>> boxes(9,vector<int>(9,0));

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {

                if(board[r][c] == '.') {
                    continue;
                }

                int val = board[r][c] - '1';

                if(rows[r][val] == 1) {
                    return false;
                }

                rows[r][val] = 1;

                if(cols[c][val] == 1) {
                    return false;
                }

                cols[c][val] = 1;

                int boxIdx = 3 * (r/3) + (c/3);
                
                if(boxes[boxIdx][val] == 1) {
                    return false;
                }
                boxes[boxIdx][val] = 1;
            }
        }
        return true;
    }
};