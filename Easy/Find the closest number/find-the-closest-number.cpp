//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   int findClosest(int n, int k, int arr[]) 
{ 
    int start = 0;
    int end = n - 1;
    
    while (start <= end) 
    {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == k)
            return arr[mid];
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // After the loop, 'start' will be the insertion point.
    // We need to check the closest element around the insertion point.
    if (start >= n) // 'k' is greater than all elements
        return arr[n - 1];
    if (start == 0) // 'k' is less than all elements
        return arr[0];

    // Otherwise, compare the two closest candidates
    int val1 = arr[start];
    int val2 = arr[start - 1];

    // If they are equally close, return the greater value
    if (abs(val1 - k) < abs(val2 - k))
        return val1;
    else if (abs(val1 - k) > abs(val2 - k))
        return val2;
    else // abs(val1 - k) == abs(val2 - k)
        return val1 > val2 ? val1 : val2;
}

};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends