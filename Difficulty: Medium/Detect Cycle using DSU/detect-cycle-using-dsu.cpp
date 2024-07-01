//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    vector<int>parent;
vector<int>rank;

int DSUfind(int i)
{
    if(parent[i]==i)
        return i;
    return parent[i]= DSUfind(parent[i]); // path compression
}


void optimiseDSUUnion(int x,int y)
{
    int x_parent=DSUfind(x);
    int y_parent=DSUfind(y);

    if(x_parent==y_parent)
        return;
    if(rank[x_parent]<rank[y_parent])
    {
        parent[x_parent]=y_parent;
    }
    else if(rank[x_parent]>rank[y_parent])
    {
        parent[y_parent]=x_parent;
    }
    else
    {
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }

}
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0; i<V; i++)
	    {
	        parent[i]=i;
	        rank[i]=1;
	    }
	    for(int i=0; i<V; i++)
	    {
	        for(auto &u:adj[i])
	        {
	            if(i<u)
	            {
	                int u_parent=DSUfind(u);
	                int i_parent=DSUfind(i);
	                if(u_parent==i_parent)
	                    return true;
	               
	               optimiseDSUUnion(i,u);
	            }
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends