//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string, string> emailToName;
        unordered_map<string, unordered_set<string>> graph;
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                emailToName[account[i]] = name;
                graph[account[i]].insert(account[1]);
                graph[account[1]].insert(account[i]);
            }
        }
        
        vector<vector<string>> mergedAccounts;
        unordered_set<string> visited;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            const string& email = it->first;
            const unordered_set<string>& neighbors = it->second;
            if (!visited.count(email)) {
                vector<string> component;
                dfs(email, graph, visited, component);
                sort(component.begin(), component.end());
                component.insert(component.begin(), emailToName[email]);
                mergedAccounts.push_back(component);
            }
        }
        
        return mergedAccounts;
    }

private:
    void dfs(const string& email, unordered_map<string, unordered_set<string>>& graph, unordered_set<string>& visited, vector<string>& component) {
        visited.insert(email);
        component.push_back(email);
        for (const auto& neighbor : graph[email]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, graph, visited, component);
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends