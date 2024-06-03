//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int helper(string &str,string &x,int n,int m, vector<vector<int>>&t)
{
    if(n==0)
    {
        return 0;
    }
    if(t[n][m]!=-1)
    {
        return t[n][m];
    }
    if(str[n-1]==x[m-1])
    {
        t[n][m]=1+helper(str,x,n-1,m-1,t);
    }
    else
    {
        t[n][m]=max(helper(str,x,n-1,m,t),helper(str,x,n,m-1,t));
    }
    return t[n][m];
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string x=str;
reverse(str.begin(),str.end());
vector<vector<int>>t(n+1,vector<int>(n+1,-1));
    return str.length()-helper(str,x,n,n,t);
} 