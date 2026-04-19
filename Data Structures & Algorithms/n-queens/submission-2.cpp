class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols, diag, adiag;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // diag r + c
        // r - c
       backtrack(0, n, board);
       return res;
    }
    void backtrack(int r, int n, vector<string>& board) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (cols.count(c) || diag.count(r + c) || adiag.count(r -c)) {
                continue;
            }
            cols.insert(c);
            diag.insert(r + c);
            adiag.insert(r - c);
            board[r][c] = 'Q';
            backtrack(r + 1, n, board);
            cols.erase(c);
            diag.erase(r + c);
            adiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};
