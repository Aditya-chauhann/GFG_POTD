//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isEularCircuitExist(int v, vector<int> adj[]) {
        // Counting the degrees of all vertices
        unordered_map<int, int> degrees;
        for (int i = 0; i < v; ++i) {
            degrees[i] = adj[i].size();
        }
        
        // Checking if all vertices have even degrees
        for (auto& kv : degrees) {
            if (kv.second % 2 != 0)
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends