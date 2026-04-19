class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>> &board, string &word, int k) {
        
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || board[i][j] != word[k] || board[i][j] == ',') return false;
        
        if (k == word.size() - 1) {
            return true;
        }
        
        char saved = board[i][j];
        board[i][j] = ',';
        bool ok = false;
        ok |= dfs(i - 1, j, board, word,k + 1);
        ok |= dfs(i + 1, j, board, word,k + 1);
        ok |= dfs(i, j - 1, board, word,k + 1);
        ok |= dfs(i, j + 1, board, word, k + 1);
        board[i][j] = saved;
        return ok;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool res = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string cur(1, board[i][j]);
                res |= dfs(i,j,board,word, 0);
            }
        }
        return res;
    }
};
