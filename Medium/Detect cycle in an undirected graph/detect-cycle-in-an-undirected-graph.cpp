//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool DFS(int v, vector<bool>& visited, vector<int> adj[], int parent) {
    visited[v] = true;

    for (auto x : adj[v]) {
        if (!visited[x]) {
            if (DFS(x, visited, adj, v)) {
                return true;
            }
        } else if (x != parent) { // Corrected from v != parent to x != parent
            return true;
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (DFS(i, visited, adj, -1)) {
                return true;
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends