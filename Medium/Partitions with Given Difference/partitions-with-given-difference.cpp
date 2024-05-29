//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 int mod = 1e9 + 7;

int helper(int n, int target, const vector<int>& arr, vector<vector<int>>& dp) {
    if (n == 0) {
        return target == 0 ? 1 : 0;
    }
    if (dp[n][target] != -1) {
        return dp[n][target];
    }

    if (arr[n - 1] <= target) {
        dp[n][target] = (helper(n - 1, target - arr[n - 1], arr, dp) + helper(n - 1, target, arr, dp)) % mod;
    } else {
        dp[n][target] = helper(n - 1, target, arr, dp) % mod;
    }

    return dp[n][target];
}

int countPartitions(int n, int d, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int target = d + sum;
    
    if (target % 2 != 0) {
        return 0;
    }

    target /= 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return helper(n, target, arr, dp);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends