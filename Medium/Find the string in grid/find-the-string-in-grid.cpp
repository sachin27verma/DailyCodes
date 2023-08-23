//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>v;
	    char t=word[0];
	    int k=word.length();
	    for(int i=0; i<n; i++ )
	    {
	        for(int j=0; j<m; j++)
	        {
	        vector<int>temp;
	            if(grid[i][j]==t)
	            {
	                if(j>=(k-1))
	                {
	                     string p;
	                    int index=j;
	                    int ct=k;
	                    while(ct>0)
	                    {
	                        p.push_back(grid[i][index]);
	                        index--;
	                        ct--;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	               
	                if((m-j)>=k)
	                {
	                     string p;
	                    int index=j;
	                    int ct=k;
	                    while(ct>0)
	                    {
	                        p.push_back(grid[i][index]);
	                        index++;
	                        ct--;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                if((n-i)>=k)
	                {
	                     string p;
	                    int index=i;
	                    int ct=k;
	                    while(ct>0)
	                    {
	                        p.push_back(grid[index][j]);
	                        index++;
	                        ct--;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                
	                if(i>=(k-1))
	                {
	                     string p;
	                    int index=i;
	                    int ct=k;
	                    while(ct>0)
	                    {
	                        p.push_back(grid[index][j]);
	                        index--;
	                        ct--;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                 if((m-j)>=k && (n-i)>=k)
	                {
	                     string p;
	                     int index1=i;
	                    int index2=j;
	                    int ct=0;
	                    while(ct<k)
	                    {
	                        p.push_back(grid[index1][index2]);
	                        index1++;
	                        index2++;
	                        ct++;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                 if(j>=(k-1) && i>=(k-1))
	                {
	                     string p;
	                     int index1=i;
	                    int index2=j;
	                    int ct=0;
	                    while(ct<k)
	                    {
	                        p.push_back(grid[index1][index2]);
	                        index1--;
	                        index2--;
	                        ct++;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                 if(j>=(k-1) && (n-i)>=k )
	                {
	                     string p;
	                     int index1=i;
	                    int index2=j;
	                    int ct=0;
	                    while(ct<k)
	                    {
	                        p.push_back(grid[index1][index2]);
	                        index1++;
	                        index2--;
	                        ct++;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	                 if((m-j)>=k && i>=(k-1) )
	                {
	                     string p;
	                     int index1=i;
	                    int index2=j;
	                    int ct=0;
	                    while(ct<k)
	                    {
	                        p.push_back(grid[index1][index2]);
	                        index1--;
	                        index2++;
	                        ct++;
	                    }
	                    if(p==word)
	                    {
	                        temp.push_back(i);
	                        temp.push_back(j);
	                        v.push_back(temp);
	                        continue;
	                    }
	                }
	               
	            }
	        }
	    }
	    sort(v.begin(),v.end());
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends