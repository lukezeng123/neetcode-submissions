class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        word = false;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode *root) {
        if (j == word.size() && root->word == true) return true;
        if (j == word.size() && root->word != true) return false;
            char c = word[j];
            if (c == '.') {
                for (TrieNode *child : root->children) {
                    if (child != nullptr && dfs(word, j + 1, child)) {
                        return true;
                    }
                }
            } else {
                if (root->children[c - 'a'] != nullptr && dfs(word, j + 1,root->children[c - 'a'])) {
                    return true;
                } else {
                    return false;
                }
            }
        return false;
    }


};
