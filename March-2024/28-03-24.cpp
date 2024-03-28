//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution 
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<pair<int, int>> adj[n];
        for (auto i : edges)
        {
            int u = i[0], v = i[1], wt = i[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int city = -1, minCount = INT_MAX;
    
        for (int src = 0; src < n; src++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
            dist[src][src] = 0;
            pq.push({0, src});
    
            while (!pq.empty())
            {
                auto p = pq.top();
                pq.pop();
    
                int w = p.first, node = p.second;
    
                for (auto nei : adj[node])
                {
                    int v = nei.first, wt = nei.second;
    
                    if (w + wt < dist[src][v])
                    {
                        dist[src][v] = w + wt;
                        pq.push({dist[src][v], v});
                    }
                }
            }
    
            int count = 0;
            for (int i = 0; i < n; i++)
                if (src != i and dist[src][i] <= distanceThreshold)
                    count++;
    
            if (count < minCount)
            {
                minCount = count;
                city = src;
            }
            else if (count == minCount)
                city = max(city, src);
        }
    
        return city;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends