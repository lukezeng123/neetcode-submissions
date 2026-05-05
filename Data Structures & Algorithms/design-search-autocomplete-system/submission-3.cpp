class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> sentences;

    
};
class AutocompleteSystem {
public:
void addToTrie(const string& sentence, int count) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sentences[sentence] += count;
        }
    }
    TrieNode* root;
    TrieNode* currNode;
    TrieNode* dead;
    string currSentence;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        dead = new TrieNode();
        currNode = root;
        currSentence = "";
        for (int i = 0; i < sentences.size(); i++) {
            addToTrie(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            addToTrie(currSentence, 1);
            currSentence = "";
            currNode = root;
            return {};
        }
        currSentence += c;
        if (currNode->children.find(c) == currNode->children.end()) {
            currNode = dead;
            return {};
        }

        currNode = currNode->children[c];
        vector<pair<int,string>> items;
        for (const auto& [sentence, count] : currNode->sentences) {
            items.push_back({-count,sentence});
        }
        sort(items.begin(),items.end());
        vector<string> ans;
        for (int i = 0; i < min(3,(int)items.size()); i++) {
            ans.push_back(items[i].second);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
