//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        vector<int>b(31,0);
        
        long long ans = 0 ; 
        
        for(int i=0;i<n;i++)
        {
            int M = 0 ; 
            int num = arr[i];
            for(int j=0;j<31;j++)
            {
                int t = 1 & (num>>j);
                if(t)
                {
                   ans+=(1ll*b[j]*pow(2,M));
                   b[j]++;
                }
                M++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends