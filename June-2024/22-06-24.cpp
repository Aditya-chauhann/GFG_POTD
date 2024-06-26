//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        stringstream ss(sentence);
        string input;
        long long ans = -1;
        while(getline(ss,input,' ')){
            bool check = true;
            if(input[0] >= '0' and input[0] <= '9'){
                for(int i = 0 ; i < input.size() ; i++){
                    if(input[i] == '9'){
                        check = false;
                        break;
                    }
                }
                if(check){
                    ans = max(ans,stoll(input));
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
