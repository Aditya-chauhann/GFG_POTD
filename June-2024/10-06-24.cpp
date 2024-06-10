//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        vector<char> hold;
        char ch[] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        for(int i=0; i<9; i++){
            if(find(nuts, nuts+n, ch[i]) != nuts+n)
                hold.push_back(ch[i]);
        }
        for(int i=0; i<n; i++){
            nuts[i] = hold[i];
            bolts[i] = hold[i];
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
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends