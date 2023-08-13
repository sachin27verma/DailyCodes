//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
       long  left=-1;
        long  right=-1;
    long  int start=0; 
    long   int end=v.size()-1;
        while(start<=end)
        {
            long int mid=start + (end-start)/2;
            if(v[mid]==x)
            {
                left=mid;
                end=mid-1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
      start=0; 
     end=v.size()-1;
        while(start<=end)
        {
            long int mid=start + (end-start)/2;
            if(v[mid]==x)
            {
                right=mid;
                start=mid+1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
        return {left,right};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends