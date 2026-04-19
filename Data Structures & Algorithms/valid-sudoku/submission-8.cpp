class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9][9];
        int row[9][9];
        int squares[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                col[i][j] = 0, row[i][j] = 0, squares[i][j] = 0;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (col[j][board[i][j] - '1']++ > 0) return false;
                    if (row[i][board[i][j] - '1']++ > 0) return false;
                    if (squares[(i / 3) * 3 + (j / 3)][board[i][j] - '1']++ > 0) return false;
                }
            }
        }
        return true;
    }
};
