//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long > ans;
        long long x=1;
        long long y=1;
        ans.push_back(x);
        ans.push_back(y);
        if(n==1)
        {
            return {1};
        }
        if(n==2)
        {
            return {1,1};
        }
        for(int i=2; i<n; i++)
        {
            long long temp=x+y;
            ans.push_back(temp);
            y=x;
            x=temp;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends