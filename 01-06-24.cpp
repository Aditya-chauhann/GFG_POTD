//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   string oddEven(string s) {
        vector<int> v(26,0);
        int x=0,y=0;
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if((i+1)%2==1 && v[i]!=0)
            {
                if(v[i]%2==1)
                y++;
            }
            if((i+1)%2==0 && v[i]!=0)
            {
                if(v[i]%2==0)
                x++;
            }
        }
        return (x+y)%2==0?"EVEN":"ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends