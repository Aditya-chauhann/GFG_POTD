//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int lo,int hi){
        if(lo == hi){
            while(lo > 0){
                if(lo%10 == 4){
                    return 1;
                }
                lo/=10;
            }
            return 0;
        }
        if(lo > hi){
            return 0;
        }
        int mid = lo+(hi-lo)/2;
        int ct1 = solve(lo,mid);
        int ct2 = solve(mid+1,hi);
        return ct1 + ct2;
    }
    int countNumberswith4(int n) {
        return solve(1,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
