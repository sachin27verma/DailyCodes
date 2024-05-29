//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int t[1001][1001];
  int helper(int price[],int n,int N)
  {
      if(N==0 || n==0)
        return 0;
    if(t[n][N]!=-1)
        return t[n][N];
        
      if(n<=N)
      {
          t[n][N]= max(price[n-1]+helper(price,n,N-n),helper(price,n-1,N));
      }
      else
      {
          t[n][N]= helper(price,n-1,N);
      }
      return t[n][N];
  }
    int cutRod(int price[], int n) {
        //code here
        memset(t,-1,sizeof(t));
    return helper(price,n,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends