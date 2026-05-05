class FileSystem {
public:
    struct Dir {
        unordered_map<string,Dir*> dirs;
        unordered_map<string,string> files;
    };

    FileSystem() {
        root = new Dir();
    }

    vector<string> parse(string path) {
        stringstream ss(path);
        string s;

        if (path == "/") return {};
        vector<string> res;
        getline(ss,s,'/');
        while (getline(ss,s,'/')) {
            res.push_back(s);
        }
        return res;
    }
    
    vector<string> ls(string path) {
        vector<string> res;
        if (path == "/") {
            for (auto& [u,v] : root->dirs) {
                res.push_back(u);
            }
            for (auto& [u,v] : root->files) {
                res.push_back(u);
            }
            sort(res.begin(),res.end());
            return res;
        }
        vector<string> p = parse(path);
        Dir* cur = root;
        for (int i = 0; i < p.size() - 1; i++) {
            cur = cur->dirs[p[i]];
        }
        
        if (cur->dirs.find(p[p.size() - 1]) != cur->dirs.end()) {
            cur = cur->dirs[p[p.size() - 1]];
            for (auto&[ u,v] : cur->files) {
                res.push_back(u);
            }
            for (auto&[ u,v] : cur->dirs) {
                res.push_back(u);
            }
            sort(res.begin(),res.end());
        } else {
            res.push_back(p[p.size() - 1]);
        }
        return res;
    }
    
    void mkdir(string path) {
        if (path == "/") return;
        vector<string> p = parse(path);
        Dir* cur = root;
        for (int i = 0; i < p.size(); i++) {
            if (!cur->dirs.contains(p[i])) {
                cur->dirs[p[i]] = new Dir();
            }
            cur = cur->dirs[p[i]];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> p = parse(filePath);
        Dir* cur = root;
        for (int i = 0; i < p.size() - 1; i++) {
            if (!cur->dirs.contains(p[i])) {
                cur->dirs[p[i]] = new Dir();
            }
            cur = cur->dirs[p[i]];
        }
        cur->files[p[p.size() - 1]] += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> p = parse(filePath);
        Dir* cur = root;
        for (int i = 0; i < p.size() - 1; i++) {
            cur = cur->dirs[p[i]];
        }
        return cur->files[p[p.size() - 1]];
    }
private:
    Dir* root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
