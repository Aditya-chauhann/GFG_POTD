//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
       int right = (n >> 4);
       int left = (n << 4) & 255;
    //   cout<<right<<" "<<left<<endl;
    // here after left shifting the number is in the binary form is this 11001000000 so when we find it's decimal then it would be the 1600
    // so we should anding with the max 8 bit number 11111111 which is 255 in decimal...so after  anding the final number becomes
    // 00001000000 so it make remaining bit to zero after anding which is more then the 8 bit length( first 3 bit from the left side in binary form )
    // so that's why this solution works
       return right + left;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
