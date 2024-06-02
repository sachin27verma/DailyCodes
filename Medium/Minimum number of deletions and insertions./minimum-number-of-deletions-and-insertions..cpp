//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int LCS(int n,int m, string &str1,string &str2,vector<vector<int>>&t)
	{
	    if(n==0 || m==0)
	    {
	        return 0;
	    }
	    if(t[n][m]!=-1)
	    {
	        return t[n][m];
	    }
	    if(str1[n-1]==str2[m-1])
	    {
	        t[n][m]=1+LCS(n-1,m-1,str1,str2,t);
	    }
	    else
	    {
	        t[n][m]=max(LCS(n-1,m,str1,str2,t),LCS(n,m-1,str1,str2,t));
	    }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.size();
	    int m=str2.size();
	    vector<vector<int>>t(n+1,vector<int>(m+1,-1));
	    return (n+m-2*LCS(n,m,str1,str2,t));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends