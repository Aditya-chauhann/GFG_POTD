//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    void common(string first, string second, string &res)
    {
        int i = 0, j = 0;
        int count = 0;
        string temp = "";
        while(i < first.size() && j < second.size())
        {
            if(first[i] == second[j])
            {   
                temp += first[i];
                count++;
            }
            else
            {
                res = temp;
                return;
            }
            i++;
            j++;
        }
        
        res = temp;
        return;
    }
    string longestCommonPrefix(vector<string> arr) 
    {
        //string temp = arr[0];
        string temp = arr[0];
        int len = 0;
        
        if(arr.size() == 1)
            return arr[0];
            
        for(int i = 1; i < arr.size(); i++)
        {
            
            common(arr[i],temp,temp);
        }
        if(temp.size() == 0)
            return "-1";
        else
            return temp;
        // your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
