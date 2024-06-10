//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
    // map<char, int> mpnuts;
    // map<char, int> mpbolts;

    // // Populate maps with nuts and bolts
    // for (int i = 0; i < n; i++) {
    //     mpnuts[nuts[i]] = i;
    //     mpbolts[bolts[i]] = i;
    // }
    
    // vector<char> v = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
    // int currindex = 0;

    // // Match nuts and bolts
    // for (int i = 0; i < 9; i++) {
    //     if (mpnuts.find(v[i]) != mpnuts.end() ) {
    //         if (nuts[currindex] != v[i]) {
    //             int nut_index = mpnuts[v[i]];
    //             int bolt_index = mpbolts[v[i]];

    //             swap(nuts[currindex], nuts[nut_index]);
    //             swap(bolts[currindex], bolts[bolt_index]);

    //             // Update the maps after swapping
    //             // mpnuts[nuts[nut_index]] = nut_index;
    //             mpnuts[nuts[currindex]] = currindex;
    //             // mpbolts[bolts[bolt_index]] = bolt_index;
    //             mpbolts[bolts[currindex]] = currindex;
    //         }
    //         currindex++;
    //     }
    // }
    sort(bolts,bolts+n);
        sort(nuts,nuts+n);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends