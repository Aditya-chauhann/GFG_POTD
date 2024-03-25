//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string add(string a,string b)
{
   int i=a.size()-1,j=b.size()-1;
   string res="";
   int sum,carry=0;
   while(i>=0 or j>=0)
   {
     sum=carry +(i>=0?(a[i--]-'0'):0)+(j>=0?(b[j--]-'0'):0);
     res.push_back(sum%10 +'0');
     carry=sum/10;
   }
   
   if(carry)
   res.push_back(carry+'0');
   
   reverse(res.begin(),res.end());
   return res;
}


bool check(string a,string b,string rest)
{
   if((a.size()>1 and a[0]=='0') or(b.size()>1 and b[0]=='0'))
   return false;
   
   string sum=add(a,b); // function to add strings
   
   if(sum==rest)
   return true;
   
   if(sum.size()>=rest.size()) // cannot add something and make it smaller
   return false;
   
   if(rest.substr(0,sum.size())!=sum) // starting digits of the rest substring must match 
   return false;
   
   else return check(b,sum,rest.substr(sum.size())); // recursive call
}

bool isAdditiveSequence(string s)
{
   int n=s.size();
   for(int i=1;i<=n/2;i++)
    for(int j=1;j<=(n-i)/2;j++)
      if(check(s.substr(0,i),s.substr(i,j),s.substr(i+j)))
        return true;
        
   return false;         
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends