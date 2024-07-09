//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
    int maxi = INT_MAX; // We will use maxi to store the closest sum
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int diff = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;
        int temp_target = target - arr[i];

        while (j < k) {
            int current_sum = arr[j] + arr[k];
            int current_diff = abs(temp_target - current_sum);

            if (current_diff < diff) {
                diff = current_diff;
                maxi = arr[i] + arr[j] + arr[k];
            } else if (current_diff == diff) {
                maxi = max(maxi, arr[i] + arr[j] + arr[k]);
            }

            if (current_sum < temp_target) {
                j++;
            } else {
                k--;
            }
        }
    }

    return maxi;
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
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends