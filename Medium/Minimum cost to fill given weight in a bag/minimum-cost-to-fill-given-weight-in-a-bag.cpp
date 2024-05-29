//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int t[201][201];
  int helper(int n,int w,vector<int>cost,int i)
  {
      if(t[w][i]!=-1)
      {
          return t[w][i];
      }
      
      if(i==0)
      {
          return t[w][i]= INT_MAX;
      }
      
      if(w==0)
      {
          return t[w][i]= 0;
      }
      
      if(cost[i]==-1)
      {
          return t[w][i]= helper(n,w,cost,i-1);
      }
      
      if(i<=w)
      {
          return t[w][i]= min(cost[i-1]+helper(n,w-i,cost,i),helper(n,w,cost,i-1));
      }
      else
      {
          return t[w][i]= helper(n,w,cost,i-1);
      }
      
      return t[w][i]= -1;
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        memset(t,-1,sizeof(t));
        
        return helper(n,w,cost,cost.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends