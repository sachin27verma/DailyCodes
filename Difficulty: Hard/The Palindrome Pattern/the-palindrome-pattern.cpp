//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        string ans="";
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0; i<n; i++)
        {
            int j=0; 
            int k=m-1;
            bool flag=true;
            while(j<=k)
            {
                if(arr[i][j]!=arr[i][k])
                {
                    flag=false;
                    break;
                    
                }
                j++;
                k--;
            }
            if(flag)
            {
                ans+=to_string(i);
                ans+=" R";
                return ans;
            }
        }
        
        for(int i=0; i<m; i++)
        {
            int j=0; 
            int k=n-1;
            bool flag=true;
            while(j<=k)
            {
                if(arr[j][i]!=arr[k][i])
                {
                    flag=false;
                    break;
                }
                j++;
                k--;
            }
            if(flag)
            {
                ans+=to_string(i);
                ans+=" C";
                return ans;
            }
        }
        return "-1";
        
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends