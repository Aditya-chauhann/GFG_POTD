//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
bool solve(string A, unordered_map<string,int>&mp, int ind){
        if(ind>=A.length()){
            return true;
        }
        
        for(int i=ind;i<A.length();i++){
            string s=A.substr(ind, i-ind+1);
            if(mp.find(s)!=mp.end()){
                if(solve(A, mp, i+1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    int func(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>mp;
        for(int i=0;i<B.size();i++){
            mp[B[i]]++;
        }
        
        if(solve(A, mp, 0)){
            return true;
        }
        else{
            return false;
        }
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        return func(s, dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends