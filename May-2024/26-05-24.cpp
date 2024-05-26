//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int dp[1001][1001];
    
    int check(int ind1, int ind2, const std::string &x, const std::string &y, int costX, int costY) {
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if (ind1 == x.size()) {
            return (y.size() - ind2) * costY;
        }
        if (ind2 == y.size()) {
            return (x.size() - ind1) * costX;
        }
        if (x[ind1] == y[ind2]) {
            return dp[ind1][ind2] = check(ind1 + 1, ind2 + 1, x, y, costX, costY);
        } else {
            return dp[ind1][ind2] = std::min(check(ind1 + 1, ind2, x, y, costX, costY) + costX, check(ind1, ind2 + 1, x, y, costX, costY) + costY);
        }
    }
    
public:
    int findMinCost(const std::string &x, const std::string &y, int costX, int costY) {
        std::memset(dp, -1, sizeof(dp));
        return check(0, 0, x, y, costX, costY);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
