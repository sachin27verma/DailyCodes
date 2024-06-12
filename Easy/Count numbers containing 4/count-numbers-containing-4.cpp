//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ct=0;
        for(int i=1; i<=n; i++)
        {
            int temp=i;
            while(temp!=0)
            {
                int x=temp%10;
                if(x==4)
                {
                    ct++;
                    break;
                }
                temp=temp/10;
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends