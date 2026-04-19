class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (board[i][j] == 'O') {
            board[i][j] = 't';
        } else {
            return;
        }

        if (i - 1 >= 0) {
            dfs(i - 1, j, board);
        }
        if (j - 1 >= 0) {
            dfs(i, j - 1, board);
        }
        if (i + 1 < n) {
            dfs(i + 1, j, board);
        } 
        if (j + 1 < m) {
            dfs(i, j + 1, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if (board[n - 1][i] == 'O') {
                dfs(n - 1, i, board);  
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
                
            }
            if (board[i][m - 1] == 'O') {
                dfs(i, m - 1, board);  
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j =0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 't') {
                    board[i][j] = 'O';
                }
            }
        }

    }
};
