//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a){
        // Code here.
        int n = a.size();
        int l = 0,r = n;
        while(l<=r){
            int m = (l+r)/2;
            bool tails = false;
            if(m == 0) {
                if(a[m]>a[m+1]) return a[m];
                l = m+1; tails = true;
            }
            if(m==n-1){
                if(a[m] > a[m-1]) return a[n-1];
                r = m-1; tails = true;
            }
            if(a[m-1] < a[m] && a[m] > a[m+1]) return a[m];
            
            if(!tails){
                if(a[m] < a[m+1]) l = m+1;
                else r = m-1;
            }
        }
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends
