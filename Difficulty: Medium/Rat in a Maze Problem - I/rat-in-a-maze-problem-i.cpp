//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool isvalid(vector<vector<int>>& mat, int i, int j, int n, int m, vector<vector<bool>>& visited) {
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1 && !visited[i][j]);
}

void helper(vector<vector<int>>& mat, int i, int j, int n, int m, vector<string>& ans, string s, vector<vector<bool>>& visited) {
    if (i == n - 1 && j == m - 1) {
        ans.push_back(s);
        return;
    }

    visited[i][j] = true;

    
    if (isvalid(mat, i + 1, j, n, m, visited)) {
        helper(mat, i + 1, j, n, m, ans, s + "D", visited);
    }
   
    if (isvalid(mat, i, j - 1, n, m, visited)) {
        helper(mat, i, j - 1, n, m, ans, s + "L", visited);
    }
    
    if (isvalid(mat, i, j + 1, n, m, visited)) {
        helper(mat, i, j + 1, n, m, ans, s + "R", visited);
    }
   
    if (isvalid(mat, i - 1, j, n, m, visited)) {
        helper(mat, i - 1, j, n, m, ans, s + "U", visited);
    }

    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>>& mat) {
    vector<string> ans;
   if (mat.empty() || mat[0][0] == 0) {
        return {"-1"};
    }


    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string s = "";

    helper(mat, 0, 0, n, m, ans, s, visited);

    if (ans.empty()) {
        return {"-1"};
    }

    return ans;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends