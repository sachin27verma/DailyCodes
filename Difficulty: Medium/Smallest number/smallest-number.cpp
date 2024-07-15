//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string ans="";
        int dd=d;
        int flag=true;
        
        for(int i=0; i<d; i++)
        {
            int xx;
            if(flag)
            {
                 xx=1;
            }
            else
            {
                 xx=0;
            }
            
            s-=xx;
            // cout<<s<<" ";
            while(s>(9*(dd-1)) && xx<9)
            {
                // cout<<xx<<" ";
                xx++;
                s--;
            }
            // cout<<xx<<" ";
            
            if(xx>9 || s>(9*(dd-1)))
                return "-1";
            
            char ch=xx+'0';
            ans.push_back(ch);
            dd--;
            flag=false;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends