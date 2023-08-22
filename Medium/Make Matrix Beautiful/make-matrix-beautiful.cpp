//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n)
    {
        // code here 
        vector<long long int>row(n,0),col(n,0);
        long long int sum=0,mx;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=mat[i][j];
            }
            row[i]=sum;
        }
        mx=*max_element(row.begin(),row.end());
        
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=mat[j][i];
            }
            col[i]=sum;
        }
        mx=max(mx,*max_element(col.begin(),col.end()));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long int mmx=max(row[i],col[j]);
                ans+=mx-mmx;
                row[i]+=(mx-mmx);
                col[j]+=(mx-mmx);
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends