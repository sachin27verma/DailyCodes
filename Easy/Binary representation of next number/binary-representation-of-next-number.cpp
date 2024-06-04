//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        reverse(s.begin(),s.end());
        string ans="";
        char carry='1';
        for (auto i:s)
        {
            if(i=='1' && carry=='1')
            {
                ans.push_back('0');
                carry='1';
            }
            else if(i=='0' && carry=='1')
            {
                    ans.push_back('1');
                    carry='0';
            }
            else
            {
                ans.push_back(i);
            }
        }
        if(carry=='1')
        {
            ans.push_back('1');
        }
        
        reverse(ans.begin(),ans.end());
        int ct=0;
        for(auto i:ans)
        {
            if(i=='0')
            {
                ct++;
            }
            else
                break;
        }
        ans=ans.substr(ct,ans.length()-ct);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends