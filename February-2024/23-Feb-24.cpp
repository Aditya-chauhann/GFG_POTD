//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n=price.size();
            vector<int>temp(n,0);
            
            //first traversal was from right to left
            int maxi=price[n-1];
            for(int i=n-2;i>=0;i--){
                maxi=max(maxi, price[i]);
                temp[i]=max(temp[i+1], maxi-price[i]);
            }
            
            //second traversal
            int mini=price[0];
            for(int i=1;i<n;i++){
                mini=min(price[i],mini);
                temp[i]=max(temp[i-1], price[i]-mini+temp[i]);
            }
            
            return temp[n-1];
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends