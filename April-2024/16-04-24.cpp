//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int>rightmx(n,0),rightmn(n,0);
        rightmx[n-1]=arr[n-1];
         rightmn[n-1]=arr[n-1];
         for(int i=n-2;i>=0;i--){
             rightmx[i]=max(rightmx[i+1],arr[i]);
             rightmn[i]=min(rightmn[i+1],arr[i]);
             
         }
         int i=0,j=k-1,mn=INT_MAX,mx=INT_MIN,ans=INT_MAX;
         while(j<n){
             if(i!=0){
                 mn=min(arr[i-1],mn);
                 mx=max(arr[i-1],mx);
             }
             int temp1=mn,temp2=mx;
             if(j!=n-1){
                 temp1=min(temp1,rightmn[j+1]);
                 temp2=max(temp2,rightmx[j+1]);
             }
             ans=min(ans,abs(temp2-temp1));
             i++;
             j++;
         }
         return ans;
    }

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends