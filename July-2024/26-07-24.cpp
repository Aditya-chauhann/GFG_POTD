//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

     bool kPangram(string str, int k) {
      str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
       int n = str.length();
       
       if(n < 26) {
          return false;
       }
       if(k >= 25) {
        return true;
       }
       unordered_set<char> charSet;
       for (char c = 'a'; c <= 'z'; ++c) {
        charSet.insert(c);
       }
       
       for(int i = 0; i < n; i++) {
           if(charSet.find(str[i]) != charSet.end()) {
               charSet.erase(str[i]);
           }
       }
       
       return(charSet.empty() or charSet.size() <= k);
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
