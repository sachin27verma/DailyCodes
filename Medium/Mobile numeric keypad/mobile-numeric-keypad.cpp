//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long fun(int i,int j,vector<vector<int>> &arr,int n,vector<vector<long long>> &dp)
    {
        if(n==1)
            return 1;
        
        if(dp[arr[i][j]][n] != -1)
            return dp[arr[i][j]][n];
        long long a,b,c,d,e;
        a=b=c=d=e=0;
        
        a=fun(i,j,arr,n-1,dp);
        
        if(j-1 >= 0 && arr[i][j-1] != -1)
            b=fun(i,j-1,arr,n-1,dp);
        if(j+1 < 3 && arr[i][j+1] != -1)
            c=fun(i,j+1,arr,n-1,dp);
        if(i-1 >= 0 && arr[i-1][j] != -1)
            d=fun(i-1,j,arr,n-1,dp);
        if(i+1 < 4 && arr[i+1][j] != -1)
            e=fun(i+1,j,arr,n-1,dp);
        
        return dp[arr[i][j]][n]=a+b+c+d+e;
    }
    
    long long getCount(int n) {
        
        vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long ans=0;
        vector<vector<long long>> dp(10,vector<long long>(n+1,-1));
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]!=-1)
                {
                    ans+=fun(i,j,arr,n,dp);    
                }
            }
        }
        return ans;
        // Your code goes here
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends