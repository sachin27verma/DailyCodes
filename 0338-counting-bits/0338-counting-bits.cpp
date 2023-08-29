class Solution {
public:
vector<int> solve(int n)
{
vector<int>v(n+1);
v[0]=0;
   for(int i=1; i<=n; i++)
   {
       int k=__builtin_popcount(i);
       v[i]=k;
   }
   return v;
   
}
    vector<int> countBits(int n) {
       return solve(n);
    }
};