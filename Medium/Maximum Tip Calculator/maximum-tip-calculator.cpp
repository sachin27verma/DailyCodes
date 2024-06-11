//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  long long helper(int n, int x, int y, vector<int> &arr, vector<int> &brr, int i, int j,vector<vector<long long>>&dp) {
    if (i + j >= n) {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long atake = INT_MIN, btake = INT_MIN, ans = INT_MIN;
    if (i < x) {
        atake = arr[i + j] + helper(n, x, y, arr, brr, i + 1, j,dp);
    }
    if (j < y) {
        btake = brr[i + j] + helper(n, x, y, arr, brr, i, j + 1,dp);
    }
    long long temp = max(atake, btake);
    return  dp[i][j]=max(ans, temp);
}

long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
    // code here
    // vector<vector<long long>> dp(x + 1, vector<long long>(y + 1, -1));

    // return helper(n, x, y, arr, brr, 0, 0,dp);
    
    // vector<int,pair<int,int>>v;
    vector<pair<long long,pair<long long ,long long>>>v;
    for(int i=0; i<n; i++)
    {
        v.push_back({abs(arr[i]-brr[i]),{arr[i],brr[i]}});
        
    }
    sort(v.rbegin(),v.rend());
    long long ans=0;
    
    for(int i=0; i<n; i++)
    {
        if(x==0)
        {
            ans+=v[i].second.second;
        }
        else if(y==0)
        {
            ans+=v[i].second.first;
        }
        else
        {
            if(v[i].second.first>v[i].second.second)
            {
                ans+=v[i].second.first;
                x--;
            }
            else
            {
                ans+=v[i].second.second;
                y--;
            }
        }
    }
    return ans;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends