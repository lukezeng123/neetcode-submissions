

class FileSystem {
    struct Dir {
        unordered_map<string, Dir*> dirs;
        unordered_map<string, string> files;
    };

    Dir* root;

    vector<string> parsePath(string path) {
        string cur;
        vector<string> res;
        for (auto& c : path) {
            if (c == '/') {
                if (!cur.empty()) res.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(c);
            }
        }
        if (!cur.empty()) {
            res.push_back(cur);
        }
        
        return res;
    }
        // vector<string> parsePath(string path) {
        //     vector<string> res;
        //     stringstream ss(path);
        //     string item;
        //     while (getline(ss, item, '/')) {
        //         if (!item.empty()) res.push_back(item);
        //     }
        //     return res;
        // }
        //     }
public:
    FileSystem() {
        root = new Dir();
    }
    
    vector<string> ls(string path) {
        Dir *d = root;
        vector<string> ans;
        if (path != "/") {
            vector<string> paths = parsePath(path);
        
            for (int i = 0; i < paths.size() - 1; i++) {
                d = d->dirs[paths[i]];
            }
            if (d->dirs.find(paths[paths.size() - 1]) != d->dirs.end()) {
                d = d->dirs[paths[paths.size() - 1]];
            } else {
                auto it = d->files.find(paths[paths.size() - 1]);
                ans.push_back(it->first);
                return ans;
            }
        }
        
        for (auto& e : d->dirs) {
            ans.push_back(e.first);
        }
        for (auto& f : d->files) {
            ans.push_back(f.first);
        }
            
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> paths = parsePath(path);
        Dir *d = root;
        for (auto& p : paths) {
            if (!d->dirs.contains(p)) {
                d->dirs[p] = new Dir();
            }
            d = d->dirs[p];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Dir* d = root;
        
        vector<string> paths = parsePath(filePath);
        for (int i = 0; i < paths.size() - 1; i++) {
            if (!d->dirs.contains(paths[i])) {
                d->dirs[paths[i]] = new Dir();
            }
            d = d->dirs[paths[i]];
        }
        d->files[paths[paths.size() - 1]].append(content);
        return;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> paths = parsePath(filePath);
        Dir *d = root;
        for (int i = 0; i < paths.size() - 1; i++) {
            d = d->dirs[paths[i]];
        }
        auto it = d->files.find(paths[paths.size() - 1]);
        return it->second;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
