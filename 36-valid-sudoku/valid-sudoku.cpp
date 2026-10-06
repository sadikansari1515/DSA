class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = 9;

        vector<unordered_set<char>> rows(n);
        vector<unordered_set<char>> cols(n);
        vector<unordered_set<char>> boxes(n);

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                char cell = board[r][c];

                if (cell == '.') {
                    continue;
                }

                // Check row
                if (rows[r].count(cell)) {
                    return false;
                }

                rows[r].insert(cell);

                // Check column
                if (cols[c].count(cell)) {
                    return false;
                }

                cols[c].insert(cell);

                // Find box index
                int boxIndex = 3 * (r / 3) + (c / 3);

                // Check 3x3 box
                if (boxes[boxIndex].count(cell)) {
                    return false;
                }

                boxes[boxIndex].insert(cell);
            }
        }

        return true;
    }
};