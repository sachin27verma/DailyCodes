//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int v[], int n) {
	    // code here
	    
	    int i=0; 
    int j=0;

    while(i<n && j<n)
    {
        if(v[i]!=0 && v[j]!=0)
        {
            i++;
            j++;
        }
        else if(v[j]==0)
        {
            j++;
        }
        else{
            swap(v[i],v[j]);
            i++;
            
        }
    }
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
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends