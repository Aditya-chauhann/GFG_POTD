//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // Split the string by dots
        vector<string> parts;
        stringstream ss(str);
        string part;

        while (getline(ss, part, '.')) {
            parts.push_back(part);
        }

        // An IPv4 address must have exactly four parts
        if (parts.size() != 4) {
            return false;
        }

        // Validate each part
        for (const string& part : parts) {
            // Check if the part is empty or has leading zeros
            if (part.empty() || (part.size() > 1 && part[0] == '0')) {
                return false;
            }

            // Check if the part contains only digits
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }

            // Convert part to integer and check range
            int num = stoi(part);
            if (num < 0 || num > 255) {
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
