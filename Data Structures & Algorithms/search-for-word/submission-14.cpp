class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>> board, string &word, string cur) {
        if (cur.size() == word.size()) {
            return cur == word ? true : false;
        }
        int n = board.size();
        int m = board[0].size();
        board[i][j] = ',';
        bool ok = false;
        if (i - 1 >= 0 && board[i - 1][j] != ',') ok |= dfs(i - 1, j, board, word, cur + board[i - 1][j]);
        if (i + 1 < n && board[i + 1][j] != ',') ok |= dfs(i + 1, j, board, word,cur + board[i + 1][j]);
        if (j - 1 >= 0 && board[i][j - 1] != ',') ok |= dfs(i, j - 1, board, word, cur + board[i][j - 1]);
        if (j + 1 < m && board[i][j + 1] != ',') ok |= dfs(i, j + 1, board, word, cur + board[i][j + 1]);
        return ok;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool res = false;
        vector<vector<char>> meow = board;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string cur(1, board[i][j]);
                res |= dfs(i,j,meow,word, cur);
            }
        }
        return res;   
    }
};
