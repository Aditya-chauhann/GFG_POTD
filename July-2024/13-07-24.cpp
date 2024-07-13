//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
     vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
            greater<pair<int,int>>>pq;
        
        pq.push({0,1});
        vector<int>dis(n+1,INT_MAX),par(n+1);
        for(int i=1; i<n+1;i++){
            par[i]=i;
        }
        dis[1]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dist=it.first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int weight=it.second;
                if(dist+weight<dis[adjnode]){
                    dis[adjnode]=dist+weight;
                    pq.push({dist+weight,adjnode});
                    par[adjnode]=node;
                }
            }
        }
        if(dis[n]==INT_MAX) return {-1};
        vector<int >path;
        int node=n;
        while(par[node]!=node){
            path.push_back(node);
            node=par[node];
        }
        path.push_back(1);
        path.push_back(dis[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
