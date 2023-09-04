class Solution {
public:

void dfs(int i , int j,int prevcolor , int color, vector<vector<int>>&image )
{
    int n=image.size();
    int m=image[0].size();
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=prevcolor) return;
    image[i][j]=color;
    dfs(i-1,j,prevcolor,color,image);
    dfs(i+1,j,prevcolor,color,image);
    dfs(i,j-1,prevcolor,color,image);
    dfs(i,j+1,prevcolor,color,image);

    return;

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

int initialcolor=image[sr][sc];
        if(initialcolor!=color)
        dfs(sr,sc,image[sr][sc],color,image);
        return image;
    }
};