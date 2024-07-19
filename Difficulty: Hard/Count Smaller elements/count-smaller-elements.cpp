//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
  int bs(vector<int>&temp,int target)
  {
      int index=-1;
      int low=0;
      int high=temp.size()-1;
      while(low<=high)
      {
          int mid=low+(high-low)/2;
          if(temp[mid]==target)
          {
              index=mid;
              high=mid-1;
          }
          else if(temp[mid]>target)
          {
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
      }
      return index;
  }
  
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        vector<int>ans;
        vector<int>temp;
        
        temp=arr;
        sort(temp.begin(),temp.end());
        for(int i=0; i<arr.size(); i++)
        {
            int index=bs(temp,arr[i]);
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends