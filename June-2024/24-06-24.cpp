//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        // range form 2 to 2*n
        // 2+2*n /2 = n+1 comes max times
        // n+1 comes n times
        
        if(q<2 || q>2*n){
            return 0;
        }
        else{
            if(q<=(n+1)){
                return q-1;
            }
            else{
                return 1+(2*n-q);
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends
