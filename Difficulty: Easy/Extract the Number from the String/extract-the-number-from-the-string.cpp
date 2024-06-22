//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long ans=-1;
        long long k=0;
        int flag=0;
        for(long long i=0; i<=sentence.length(); i++)
        {
            if(sentence[i]>='0' && sentence[i]<='9' )
            {
                if(flag==0)
                {
                     k=i;
                }
                flag=1;
                if(sentence[i]=='9')
                {
                    while((sentence[i]>='0' && sentence[i]<='9') && i<=sentence.length())
                    {
                        i++;
                        flag=0;
                    }
                }
            }
           else if(flag)
           {
               string temp=sentence.substr(k,i-k+1);
               long long xx=stoll(temp);
               ans=max(ans,xx);
               flag=0;
           }
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
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends