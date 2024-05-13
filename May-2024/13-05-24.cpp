//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:


    bool bfs(vector<int>adj[], int start, vector<int>&vis){
        int num =0, edges=0;
        queue<int> q;
        q.push(start);
        vis[start]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            num++;
            edges += adj[node].size();
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        
         return (num*(num-1) == edges);
    }


    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> adj[v+1];
        for(int i=0; i<e; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(v+1, 0);
        int ans=0;
        for(int i=1; i<=v; i++){
            if(bfs(adj, i, vis)){
                ans++;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
