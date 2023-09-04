class Solution {
public:
bool visited[301][301];
    void dfs(int i, int j, vector<vector<char>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0) return ;
        if(i>=n || j>=m) return ;
        if(grid[i][j]=='0') return;
        if(visited[i][j]) return;
        cout<<i<<j<<endl;
        visited[i][j]=true;
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
      
      memset(visited,false,sizeof(visited));
      int n=grid.size();
      int m=grid[0].size();
      int ct=0;
      for(int i=0; i<n; i++)
      {
          for(int j=0; j<m; j++)
          {
              if((grid[i][j]=='1') && !visited[i][j])
              {
                  ct++;
                //   cout<<i<<j<<endl;
                  dfs(i,j,grid);
              }
          }
      }
      return ct;

    }
};