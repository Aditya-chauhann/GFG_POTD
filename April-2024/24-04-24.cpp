//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dp[501][501];
    int mod = 1000000007;
    int solve(int x, int y){
        if(x==0 && y==0) return 1;
        
        if(x==0) return solve(x,y-1);
        if(y==0) return solve(x-1,y);
        
        if(dp[x][y]!=-1) return dp[x][y]%mod;
        
        int left = solve(x-1,y);
        int down = solve(x,y-1);
        
        return dp[x][y] = (left + down)%mod;
    }

    int ways(int x, int y)
    {
        //code here.
        memset(dp,-1,sizeof(dp));
        return solve(x,y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends