class TrieNode {
public:
    TrieNode* children[26];
    bool end;
    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (auto& c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->end = true;
    }

    bool search(const string& word, int i, TrieNode* cur) {
        if (i == word.size()) return cur->end;

        if (word[i] == '.') {
            bool meow = false;
            for (int j = 0; j < 26; j++) {
                if (cur->children[j] != nullptr) {
                    meow |= search(word, i + 1,cur->children[j]);
                }
            }
            return meow;
        } else {
            if (cur->children[word[i] - 'a'] != nullptr) {
                
                return search(word, i + 1,cur->children[word[i] - 'a']);
            } else {
                return false;
            }
        }

    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        root->addWord(word);
    }
    
    bool search(string word) {
        return root->search(word, 0, root);
    }
};
