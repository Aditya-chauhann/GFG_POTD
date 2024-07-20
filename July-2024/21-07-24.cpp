//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod =1e9 +7;
    long long int findMaxProduct(vector<int>& arr) {
        int neg =0;
        int maxneg =-1e9;
        long long int pospro =1ll;
        long long int negpro =1ll;
        for(int i =0;i< arr.size();i++){
            if(arr[i] < 0){
                maxneg =max(maxneg,arr[i]);
                neg++;
            }
        }
        int flag =1;
        for(int i =0;i< arr.size();i++){
            if(arr[i] < 0){
                if(neg&1 && arr[i] == maxneg && flag){
                    flag =0;
                    continue;
                }
                negpro = (1ll*negpro*abs(arr[i]))%mod;
            }
            if(arr[i] >0){
                pospro = (1ll*pospro*arr[i])%mod;
            }
        }
        return (1ll*negpro*pospro)%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
