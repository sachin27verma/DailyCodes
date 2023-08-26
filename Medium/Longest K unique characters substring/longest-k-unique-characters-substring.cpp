//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m;
    int ans=-1;
    int p=0;
    for(int i=0; i<s.length(); i++)
    {
        m[s[i]]++;
        if(m.size()==k)
        {
            int f=(i-p+1);
            ans=max(ans,f);
        }
        else if(m.size()>k)
        {
            m[s[p]]--;
            if(m[s[p]]==0)
            {
                m.erase(s[p]);
                
            }
            p++;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends