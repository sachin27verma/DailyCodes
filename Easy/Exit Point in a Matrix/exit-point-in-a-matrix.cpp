//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
       int a = 0;
    int i = 0;
    int j = 0;
    int fl = 0;
    int fr = 1;
    int fu = 0;
    int fd = 0;
    
    while (i >= 0 && i < n && j >= 0 && j < m) {
        if (matrix[i][j] == 1) {
            if (a % 4 == 0) {
                matrix[i][j] = 0;
                i++;
                if (i >= n) {
                    return { i - 1, j };
                }
                      fd=1;
                    fr=0;
                    fu=0;
                    fl=0;
                    // cout<<i<<" "<<j<<endl;
            } else if (a % 4 == 1) {
                matrix[i][j] = 0;
                j--;
                if (j < 0) {
                    return { i, j + 1 };
                }
                      fd=0;
                    fr=0;
                    fu=0;
                    fl=1;
                    // cout<<i<<" "<<j<<endl;
            } else if (a % 4 == 2) {
                matrix[i][j] = 0;
                i--;
                if (i < 0) {
                    return { i + 1, j };
                }
                      fd=0;
                    fr=0;
                    fu=1;
                    fl=0;
                    // cout<<i<<" "<<j<<endl;
            } else if (a % 4 == 3) {
                matrix[i][j] = 0;
                j++;
                if (j >= m) {
                    return { i, j - 1 };
                }
                      fd=0;
                    fr=1;
                    fu=0;
                    fl=0;
                    // cout<<i<<" "<<j<<endl;
            }
            
            a++;
        } else {
            if (fl == 1) {
                 j--;
                if (j < 0) {
                    return { i, j + 1 };
                }
                // cout<<i<<" "<<j<<endl;
                
            } else if (fr == 1) {
                j++;
                if (j >= m) {
                    return { i, j - 1 };
                }
                // cout<<i<<" "<<j<<endl;
            } else if (fu == 1) {
                i--;
                if (i < 0) {
                    return { i + 1, j };
                }
                // cout<<i<<" "<<j<<endl;
            } else if (fd == 1) {
                 i++;
                if (i >= n) {
                    return { i - 1, j };
                }
                // cout<<i<<" "<<j<<endl;
            }
        }
    }
    // Return the last valid position as the boundary point
    // return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends