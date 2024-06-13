//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    int padovanSequence(int n)
    {
       //code here
        int mod=1e9+7;;
        int a=1,b=1,c=1;
        if(n==0 || n==1 || n==2)
         return a;
        for(int i=3;i<=n;i++)
        {
            int temp=c;
            c=(b+a)%mod;
            a=b;
            b=temp;
        }
        return c;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
