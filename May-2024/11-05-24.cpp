//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void helper(long long n,vector<long long> & ans){
        if(n==1){
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        if(n%2==0){
            helper(pow(n,0.5),ans);
        }else{
            helper(pow(n,1.5),ans);
        }
    }
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        helper(n,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends