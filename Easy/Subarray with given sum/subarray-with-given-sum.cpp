//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>a, int n, long long s)
    {
        // Your code here
        int j=0;
        int k=0;
        int temp=0;
        int flag=0;
        int i=0;
       while (i<n)
        { temp+=a[i];
            if(temp<s)
            {
                i++;
            }
            else if(temp==s)
            {
                int right=i+1;
                k=right;
                break;
            }
            else
            {
                while(j<i)
                {
                    temp-=a[j];
                    j++;
                    if(temp==s)
                    {
                        flag=1;
                        break;
                    }
                    else if(temp<s)
                    {
                        break;
                    }
                    
                }
                if(flag)
                {
                    k=i+1;
                    break;
                }
                i++;
            }
        }
        if(j+1>k)
        {
            return {{-1}};
        }
        else
        return {{j+1,k}};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends