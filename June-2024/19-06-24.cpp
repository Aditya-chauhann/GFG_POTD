//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        double per= perimeter, a=area;
        double len= (per/2-sqrt(per*per/4-6*a))/6;
        return len*len*(per/4-2*len);
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends
