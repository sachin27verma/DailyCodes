//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int i, vector<int>adj[],vector<int>&color,int currcolor)
{
    color[i]=currcolor;
    for(auto &x:adj[i])
    {
        if(color[x]==currcolor)
            return false;
        if(color[x]==-1)
        {
            if(dfs(x,adj,color,1-currcolor)==false)
                return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V+1,-1);
	    int currcolor=0;
	    bool ans=true;
	    for(int i=0; i<V; i++)
	    {
	        if(color[i]==-1)
	        {
	           ans&= dfs(i,adj,color,currcolor);
	        }
	    }
	    return ans;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends