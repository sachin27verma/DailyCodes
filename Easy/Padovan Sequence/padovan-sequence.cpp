//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   long long mod=1e9+7;
   int helper(int n,vector<int>&dp)
   {
        if(n==0 || n==1 || n==2)
        {
            return dp[n]=1;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]= (padovanSequence(n-2)%mod+padovanSequence(n-3)%mod)%mod;
        return dp[n];
   }
    int padovanSequence(int n) {
        // code here.
       if(n==0 || n==1 || n==2)
        {
            return 1;
        }
        int a=1;
        int b=1;
        int c=1;
        for(int i=3; i<=n; i++)
        {
            int temp=a+b;
            temp=temp%mod;
            
            a=b;
            b=c;
            c=temp;
            a=a%mod;
            b=b%mod;
            c=c%mod;
        }
        return c;
       
       
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends