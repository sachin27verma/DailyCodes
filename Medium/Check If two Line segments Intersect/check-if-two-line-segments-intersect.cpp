//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 float slope(int p[], int q[]) {
    float y1 = p[1];
    float y2 = q[1];
    float x1 = p[0];
    float x2 = q[0];
    
    if ((x1 - x2) == 0) {
        return numeric_limits<float>::max();
    }

    return (y1 - y2) / (x1 - x2);
}

string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
    float m1 = slope(p1, q1);
    float m2 = slope(p2, q2);
    
    if (m1 == m2) {
        return "false";
    } 
    
     bool chk211 = p2[1]-p1[1] - m1*(p2[0]-p1[0]) >0?true:false;

        bool chk212 = q2[1]-p1[1] - m1*(q2[0]-p1[0]) >0?true:false;

        bool chk121 = p1[1]-p2[1] - m2*(p1[0]-p2[0]) >0?true:false;

        bool chk122 = q1[1]-p2[1] - m2*(q1[0]-p2[0]) >0?true:false;

        if((chk211==true && chk212 == true) || (chk211==false && chk212 == false) || 

        (chk121 == true && chk122 == true) || (chk121 == false && chk122 == false)){

            return "false";

        }

        return "true";
    
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends