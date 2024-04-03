//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long MOD=1e9+7;
        int n=s.length();
        
        long long sum=s[0]-'0';
        long long cur=s[0]-'0';
        
        for(int i=1; i<n; i++){
            cur=(cur*10 + (i+1) * (s[i]-'0'))%MOD;
            sum=(sum+cur)%MOD;
        }
        return sum;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
