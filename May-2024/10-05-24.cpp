//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    set<vector<int>>st;
    void solve(vector<int>&arr,int n,int k,int i,vector<int>&temp){
        if(k<0) return ;
        if(i==n){
         if(k==0) st.insert(temp);
         return ;
        }
        temp.push_back(arr[i]);
        solve(arr,n,k-arr[i],i+1,temp);
        temp.pop_back();
        solve(arr,n,k,i+1,temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        solve(arr,n,k,0,temp);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends