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
    vector<int> getPrimes(int n) {
        // code here
       map<int, int> mp;
      vector<bool> isprime(n + 1, true);
      isprime[0] = isprime[1] = false;
      for (int i = 2; i * i <= n; i++)
      {
         if (isprime[i])
         {
               for (int j = i * i; j <= n; j += i)
               {
                  isprime[j] = false;
               }
         }
      }
     
     for(int i=2;i<=n;i++)
     {
         if(isprime[i])
         {
           int temp=n-i;
             if(isprime[temp])
             {
                return {i,temp};
             }
         }
     }
     return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends