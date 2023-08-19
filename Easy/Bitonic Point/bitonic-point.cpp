//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int nums[], int n) {
	    int ans=-1;
        int start=0;
        int end=n-1;
        if(end==0)
        {
            return 0;
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid>0 and mid<n-1)
            {
                if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1])
                {
                    return nums[mid];
                }
                else if(nums[mid+1]>nums[mid])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
            else if(mid==0)
            {
                if(nums[0]>nums[1])
                {
                    return nums[0];
                }
                else
                {
                    return nums[1];
                }
               
            }
            else 
            {
                if(nums[n-1]>nums[n-2])
                {
                    return nums[n-1];
                }
                else
                {
                    return nums[n-2];
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends