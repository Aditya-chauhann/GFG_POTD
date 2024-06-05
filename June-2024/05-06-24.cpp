//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sum1=accumulate(a,a+n,0);
        int sum2=accumulate(b,b+m,0);
        sum2-=sum1;
        // sum1 - a[i] + b[j] = sum2 - b[j] + a[i]
        // 2*b[j] = sum2-sum1 + 2*a[i];
        // so we just have to find if rhs exist in array b
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        int ans=-1;
        // we only need distinct pairs so to avoid duplicacy we can create map for array a also
        unordered_map<int,int>temp;
        for(int i=0;i<n;i++){
            temp[a[i]]++;
        }
        for(auto it:temp){
            if(sum2%2){
                continue;
            }
            else{
                int find=sum2+2*(it.first);
                if(mp[find/2]>0){
                    //cout<<it.first<<" "<<find<<endl;
                    ans++;
                }
            }
        }
        return ans==-1?-1:1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends