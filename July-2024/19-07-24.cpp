//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int>ans;
    void merge(vector<pair<int,int>>&arr,int i,int mid,int j){
        //i-->mid and mid+1-->j  is merged
        vector<pair<int,int>>b;
        int k1 = i,k2 = mid+1;
        int timber = 0;
        map<int,int>mp;
        while(k1 <= mid and k2 <= j){
            if(arr[k1].first <= arr[k2].first){
                ans[arr[k1].second] += (timber-mp[arr[k1].second]);
                b.push_back(arr[k1]);
                k1++;
            }
            else{
                ans[arr[k1].second] += (1+timber-mp[arr[k1].second]);
                b.push_back(arr[k2]);
                timber++;
                mp[arr[k1].second] = timber;
                k2++;
            }
        }
        while(k1 <= mid){
            ans[arr[k1].second] += (timber-mp[arr[k1].second]);
            b.push_back(arr[k1]);
            k1++;
        }
        while(k2 <= j){
            b.push_back(arr[k2]);
            k2++;
        }
        int ct = 0;
        for(int k=i;k<=j;k++){
            arr[k] = b[ct++];
        }
    }
    void mergeSort(vector<pair<int,int>>&arr,int i,int j){
        if(i >= j){
            return;
        }
        int mid = i+(j-i)/2;
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,j);
        merge(arr,i,mid,j);
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        vector<pair<int,int>>arr1;
        for(int i=0;i<arr.size();i++){
            arr1.push_back({arr[i],i});
        }
        ans.resize(arr.size());
        mergeSort(arr1,0,arr1.size()-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
