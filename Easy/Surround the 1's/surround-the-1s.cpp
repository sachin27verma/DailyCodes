//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& m) {
        // Code here
        // int ct=0;
        // for(int i=0; i<matrix.size(); i++)
        // {
        //         int temp=0;
        //     for(int j=0; j<matrix[i].size(); j++)
        //     {
        //         if(matrix[i][j]==1){
                    
        //         if(i!=0 )
        //         {
        //             if(matrix[i-1][j]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(i!=matrix.size()-1)
        //         {
        //             if(matrix[i+1][j]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(j!=0)
        //         {
        //             if(matrix[i][j-1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(j!=matrix[i].size()-1)
        //         {
        //             if(matrix[i][j+1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(i!=0 && j!=matrix[i].size()-1)
        //         {
        //             if(matrix[i-1][j+1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(i!=matrix.size()-1 && j!=matrix[i].size()-1)
        //         {
        //             if(matrix[i+1][j+1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(i!=0 && j!=0)
        //         {
        //             if(matrix[i-1][j-1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         if(i!=matrix.size()-1 && j!=0)
        //         {
        //             if(matrix[i+1][j-1]==0)
        //             {
        //                 temp++;
        //             }
        //         }
        //         }
                
        //     }
        //     if(temp%2==0 && temp>0)
        //     {
        //         ct++;
        //     }
        // }
        // return ct;
         int ans = 0;
       int r = m.size();
       int c = m[0].size();
       
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){


             if(m[i][j] == 1){
                int cnt =0;


               //top
               if(i-1 >= 0){
                   if(j-1 >= 0){
                       if(m[i-1][j-1] == 0) cnt++;
                   }
                   
                   if(j+1 < c){
                       if(m[i-1][j+1] == 0) cnt++;
                   }
                   
                   if(m[i-1][j] == 0) cnt++;
               }


               //bottom
               if(i+1 < r){
                   if(j-1 >= 0){
                       if(m[i+1][j-1] == 0) cnt++;
                   }
                   
                   if(j+1 < c){
                       if(m[i+1][j+1] == 0) cnt++;
                   }
                   
                   if(m[i+1][j] == 0) cnt++;
               }
               
               //left
               if(j-1 >= 0){
                   if(m[i][j-1] == 0) cnt++;
               }
               
               //right
               if(j+1 < c){
                   if(m[i][j+1] == 0) cnt++;
               }
               
               //check odd or even
               if(cnt%2 == 0 && cnt != 0) ans++;
             }
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends