//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
     int n=a.size();
       int s=0;
       int e=n-1;
       int mid=s+(e-s)/2;
       while(s<e){
           if(a[mid]<a[mid+1]){
               s=mid+1;
           }
           else {
               e=mid;
           }
           mid=s+(e-s)/2;
       }
       return a[s];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends