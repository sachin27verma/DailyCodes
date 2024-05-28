//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int dpmemoization(int arr[], int n, int sum, vector<vector<int>> &t) {
    if (sum == 0) {
        return t[n][sum] = 1;
    }
    if (n == 0) {
        return t[n][sum] = 0;
    }
    if (t[n][sum] != -1) {
        return t[n][sum];
    }
    if (arr[n - 1] <= sum) {
        return t[n][sum] = dpmemoization(arr, n - 1, sum - arr[n - 1], t) || dpmemoization(arr, n - 1, sum, t);
    }
    return t[n][sum] = dpmemoization(arr, n - 1, sum, t);
}

int minDifference(int arr[], int n) {
    int sum = accumulate(arr, arr + n, 0);
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));

    // Fill the memoization table for all sums from 0 to sum
    for (int i = 0; i <= sum; i++) {
        dpmemoization(arr, n, i, t);
    }

    int mn = INT_MAX;

    // Check only up to sum / 2 for valid subset sums
    for (int i = 0; i <= sum / 2; i++) {
        if (t[n][i] == 1) {
            mn = min(mn, abs(sum - 2 * i));
        }
    }

    return mn;
}

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends