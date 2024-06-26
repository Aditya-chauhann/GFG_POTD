//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int r=mat.size();
    int c=mat[0].size();
    int i=0;
    int j=0;
    while(i<=r-2 && j<=c-2){
        if(mat[i][j]!=mat[i+1][j+1]){
            return false;
        }
        if(i==r-2 ||j==c-2){
            j++;
            i=0;
        }
        else{
            i++;
            j++;
        }
    }
    i=0;
    j=0;
    while(i<=r-2 && j<=c-2){
        if(mat[i][j]!=mat[i+1][j+1]){
            return false;
        }
        if(i==r-2 ||j==c-2){
            i++;
            j=0;
        }
        else{
            i++;
            j++;
        }
    }
    return true;
}
