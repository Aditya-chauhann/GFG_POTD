//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool check(string temp)
    {
        int ones = 0,zeros=0;
        for(auto ch:temp)
        {
            if(ch=='1') ones++;
            else zeros++;
            if(zeros>ones) return false;
        }
        return true;
    }
    void solve(int i,int n,string temp,vector<string> &ans)
    {
        if(i>=n){
            if(check(temp))
            ans.push_back(temp);
            return ;
        }
        solve(i+1,n,temp+'1',ans);
        solve(i+1,n,temp+'0',ans);
    }
vector<string> NBitBinary(int n)
{
    vector<string> ans;
    string temp = "";
    solve(0,n,temp,ans);
    return ans;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends