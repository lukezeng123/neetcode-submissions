class TrieNode {
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int i) {

        TrieNode* cur = this;
        cur->refs++;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
            cur->refs++;
        }
        cur->idx = i;
        
    }  
};


class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // what repeated work

        // dfs from every cell -> check if so far is a word -> add to set

        // same letters so far and up to cell[i][j]
        // dp[i][j] = 
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            root->addWord(words[i],i);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board,i,j,root, words);
            }
        }
        return res;


    }

    void dfs(auto& board, int i, int j, TrieNode* root, vector<string>& words) {
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        int m = board.size();
        int n = board[0].size();
        char tmp = board[i][j];
        board[i][j] = '*';
        TrieNode* prev = root;
        root = root->children[tmp - 'a'];
        if (root == nullptr) {
            board[i][j] = tmp;
            return;
        }
        if (root->idx != -1) {
            res.push_back(words[root->idx]);
            root->idx = -1;
            root->refs--;
            if (!root->refs) {
                prev->children[tmp - 'a'] = nullptr;
                root = nullptr;
                board[i][j] = tmp;
                return;
            }
        }
        for (auto& d : dir) {
            if (i + d[0] >= 0 && i + d[0] < m && j + d[1] >= 0 && j + d[1] < n) {
                if (board[i+d[0]][j+d[1]] == '*') continue;
                if (root != nullptr) {
                    dfs(board,i+d[0],j+d[1],root,words);
                }
            }
        }
        board[i][j] = tmp;
        return;
    }
};
