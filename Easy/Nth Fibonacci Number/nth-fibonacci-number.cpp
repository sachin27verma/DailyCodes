//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        long  int m=1e9+7;
     long int x=0;
    long int y=1;
       if(n==1 || n==2)
       {
           return n-1;
       }
        for(int i=2; i<=n; i++ )
        {
           long  int temp=(x+y)%m;
           x=y;
           y=temp;
        }
        return y;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends