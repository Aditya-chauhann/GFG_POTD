//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int i=0,j=0;
        char dir='R';
        vector<int> ans;
        while(true)
        {
            vis[i][j]=1;
            ans.push_back(matrix[i][j]);
            if(dir=='R')
            {
                if(j+1<m && vis[i][j+1]==0)
                    ++j;
                else if(i+1<n && vis[i+1][j]==0)
                {
                    dir='D';
                    ++i;
                }
                else
                    break;
            }
            else if(dir=='D')
            {
                if(i+1<n && vis[i+1][j]==0)
                    ++i;
                else if(j>0 && vis[i][j-1]==0)
                {
                    dir='L';
                    --j;
                }
                else
                    break;
            }
            else if(dir=='L')
            {
                if(j>0 && vis[i][j-1]==0)
                    --j;
                else if(i>0 && vis[i-1][j]==0)
                {
                    dir='U';
                    --i;
                }
                else
                    break;
            }
            else
            {
                if(i>0 && vis[i-1][j]==0)
                    --i;
                else if(j+1<m && vis[i][j+1]==0)
                {
                    dir='R';
                    ++j;
                }
                else
                    break;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
