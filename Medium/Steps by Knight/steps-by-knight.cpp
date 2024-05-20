//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isvalid(int i,int j,vector<vector<int>> &grid,int n)
	{
	    if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==-1)
	    {
	        return true;
	        
	    }
	    
	    return false;
	}
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	   vector<vector<int>> grid(n, vector<int>(n, -1));
	   int a1=KnightPos[0];
	   int a2=KnightPos[1];
	   int b1=TargetPos[0];
	   int b2=TargetPos[1];
	   grid[a1-1][a2-1]=1;
	   grid[b1-1][b2-1]=0;
	   queue<pair<int,int>>q;
	   q.push({a1-1,a2-1});
	   int ans=0;
	   int ct=0;
	   int flag=0;
	   
	   while(!q.empty())
	   {
	       
	       int size=q.size();
	   
	           ct++;
	       while(size--)
	       {
	           pair<int,int>temp=q.front();
	           q.pop();
	           int x1=temp.first;
	           int y1=temp.second;
	           int ax[8]={1,2,1,2,-1,-2,-1,-2};
	           int ay[8]={2,1,-2,-1,2,1,-2,-1};
	           for(int i=0; i<8; i++)
	           {
	               int x=ax[i]+x1;
	               int y=ay[i]+y1;
	               if(x==(b1-1)&& y==(b2-1))
	               {
	                   return ct;
	               }
	               if(isvalid(x,y,grid,n))
	               {
	                   flag=1;
	                   grid[x][y]=-2;
	                   q.push({x,y});
	               }
	           }
	       }
	       if(flag)
	       {
	           ans=ct;
	           ans=0;
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends