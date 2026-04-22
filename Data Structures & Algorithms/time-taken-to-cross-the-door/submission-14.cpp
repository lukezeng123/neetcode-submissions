class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
       
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> enter;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> exit;
        for (int i = 0; i < arrival.size(); i++) {
            if (state[i] == 0) {
                enter.push({arrival[i],i});
            } else {
                exit.push({arrival[i],i});
            }
            
        }
        vector<int> ans(arrival.size());
        int last = 0;
        int t = 0;
        cout << enter.size() << endl;
        cout << exit.size() << endl;
        while (!enter.empty() || !exit.empty()) {
            if (!enter.empty() && !exit.empty() && enter.top().first <= t && exit.top().first <= t) {
                // 0 = not used
                // 1 = entered
                // 2 = exited
                cout << "both: " << t << endl;
                cout << last << endl;
                if (last == 0) {
                    // not used -> exit
                    cout << "meow" << endl;
                    ans[exit.top().second] = t;
                    exit.pop();
                    last = 2;
                } else if (last == 1) {
                    // entered last second ->
                    cout << "meow1" << endl;
                    ans[enter.top().second] = t;
                    enter.pop();
                    last = 1;
                } else if (last == 2) {
                    //exited last second
                    cout << "meow2" << endl;
                    cout << exit.top().second << "exiting at time :" << t << endl;
                    ans[exit.top().second] = t;
                    exit.pop();
                    last = 2;
                }
            } else if (!enter.empty() && enter.top().first <= t) {
                cout << "enter: " << t << endl;
                ans[enter.top().second] = t;
                enter.pop();
                last = 1;
            } else if (!exit.empty() && exit.top().first <= t) {
                cout << "exit: " << t << endl;
                ans[exit.top().second] = t;
                exit.pop();
                last = 2;
            } else {
                cout << "none: " << t << endl;
                last = 0; 
            }
            t++;
        }

        return ans;
    }
};
