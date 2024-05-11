//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
     
        // code here
        vector<int>ans;
        while(1)
        {
            ans.push_back(n);
            if(n==1)
            {
                break;
            }
            if(n%2==0)
            {
                double temp=sqrt(n);
                n=int(temp);
            }
            else
            {
                double temp=sqrt(n);
                n=(n*temp);
            }
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

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends