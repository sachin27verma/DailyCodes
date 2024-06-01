//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
  
int LCS(string &s1, string &s2, int n, int m, int &ans, vector<vector<int>> &t) {
    if (n == 0 || m == 0) {
        return 0;
    }
    if (t[n][m] != -1) {
        return t[n][m];
    }
    LCS(s1, s2, n-1, m, ans, t); // Exploring the other subproblems
    LCS(s1, s2, n, m-1, ans, t);

    if (s1[n-1] == s2[m-1]) {
        t[n][m] = 1 + LCS(s1, s2, n-1, m-1, ans, t);
        ans = max(ans, t[n][m]);
    } else {
        t[n][m] = 0;
    }

    return t[n][m];
}

int longestCommonSubstr(string s1, string s2, int n, int m) {
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    int ans = 0;
    LCS(s1, s2, n, m, ans, t);
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends