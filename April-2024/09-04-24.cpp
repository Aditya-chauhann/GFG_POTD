//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 
public:
int solve(vector<vector<int>>&points,int m,int n,int i,int j,vector<vector<int>>&dp){
    
    if(i>=m || j>=n)
    return INT_MAX;
    
    if(i==m-1 && j==n-1){
        return 1-points[i][j];
    }
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
   int ans1=solve(points,m,n,i+1,j,dp);
   int ans2=solve(points,m,n,i,j+1,dp);
   
    return dp[i][j]=max(1,min(ans1,ans2)-points[i][j]);
    
}
int minPoints(int m, int n, vector<vector<int>> points) 
{ 
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int ans=solve(points,m,n,0,0,dp);
    return ans;
} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends