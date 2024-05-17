//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
bool DFS(int v, vector<bool>& visited, vector<bool>& recStack, vector<int> adj[]) {
    visited[v] = true;
    recStack[v] = true;

    for (auto x : adj[v]) {
        if (!visited[x]) {
            if (DFS(x, visited, recStack, adj)) {
                return true;
            }
        } else if (recStack[x]) {
            return true;
        }
    }

    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

bool isCyclic(int v, vector<int> adj[]) {
    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (DFS(i, visited, recStack, adj)) {
                return true;
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends