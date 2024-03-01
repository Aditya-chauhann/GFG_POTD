//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int minValue(string s, int k){
        // code here
        
    
        int minSum = 0;

        // Create a freq array, with initial value as 0
        int freq[26];
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }

        // Traverse the original string and calculate the frequency of every character
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Create a priority queue and store the frequency of each character
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }

        // Remove k characters
        for (int i = 0; i < k; i++) {
            // Remove the character with maximum frequency
            int curr = pq.top();
            pq.pop();
            // Reduce the frequency
            curr--;
            if (curr != 0) {
                pq.push(curr);
            }
        }

        // Min sum is the sum of squares of elements in priority queue
        while (!pq.empty()) {
            minSum += (pq.top() * pq.top());
            pq.pop();
        }

        return minSum;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends