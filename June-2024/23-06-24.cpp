//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> bracketNumbers(string s) {
        // Your code goes here
        vector<int> bn1;
        vector<int> bn2;
        int item = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '('){
                item++;
                bn1.push_back(item);
                bn2.push_back(item);
            }else if(s[i] == ')'){
                bn2.push_back(bn1.back());
                bn1.pop_back();
                
            }
        }
        return bn2;
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

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
