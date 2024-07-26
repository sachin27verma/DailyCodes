//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        map<char,int>mp;
        int ct=0;
        for(auto ch:str)
        {
            if(ch!=' ')
            {
                
                mp[ch]++;
                ct++;
                
            }
        }
        int xx=mp.size();
        
        if(ct<26)
        {
            return false;
        }
        
        int remain=str.length()-xx;
        
        int need=26-xx;
        
        if(need>0)
        {
            if(k>=need )
                return true;
            else
                return false;
        }
        else
        {
            return true;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends