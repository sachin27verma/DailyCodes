//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int pivotindex(vector<int>&arr,int n)
  {
      int l=0;
      int r=n-1;
      
      while(l<r)
      {
          int mid=l+(r-l)/2;
          if(arr[mid]>arr[r])
          {
              l=mid+1;
          }
          else
          {
              r=mid;
          }
      }
      return r;
  }
  
  int binarysearch(vector<int>&arr,int low,int high,int target)
  {
      while(low<=high)
      {
          int mid=low+(high-low)/2;
          if(arr[mid]==target)
          {
              return mid;
          }
          else if(arr[mid]>target)
          {
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
      }
      return -1;
  }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n=arr.size();
        int idx=pivotindex(arr,n);
        
        int indx1=binarysearch(arr,0,idx-1,key);
        if(indx1!=-1)
        {
            return indx1;
        }
        return binarysearch(arr,idx,n-1,key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends