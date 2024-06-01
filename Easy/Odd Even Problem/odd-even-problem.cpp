//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        int x=0;
        int y=0;
        int ct=1;
        set<char>ss;
        for(auto i:s)
        {
            ss.insert(i);
        }
        for(auto i:ss)
        {
            if(i%2==0 && mp[i]%2==0)
            {
                x++;
            }
            else if(i%2 && mp[i]%2)
            {
                y++;
            }
            ct++;
            // cout<<"x "<<x<<" y"<<y;
        }
        if((x+y)%2)
        {
            return "ODD";
        }
        else{
            return "EVEN";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends