class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans=INT_MIN;
        int n=nums.size();
       int temp=1;
       for(int i=0; i<n; i++)
       {
           temp*=nums[i];
           ans=max(ans,temp);
           if(temp==0)
           {
               temp=1;
           }
       }
       temp=1;
       for(int i=n-1; i>=0; i--)
       {
           temp*=nums[i];
           ans=max(ans,temp);
           if(temp==0)
           {
               temp=1;
           }
       }
       return ans;
    }
};