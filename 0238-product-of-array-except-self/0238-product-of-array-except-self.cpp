class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix_mul(n);
        vector<int>suffix_mul(n);
        prefix_mul[0]=1;
        for(int i=1; i<n; i++)
        {
            prefix_mul[i]=prefix_mul[i-1]*nums[i-1];
        }
        suffix_mul[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            suffix_mul[i]=suffix_mul[i+1]*nums[i+1];
        }
        vector<int>ans;
        for(int i=0; i<n; i++)
        {
            int temp=prefix_mul[i]*suffix_mul[i];
            ans.push_back(temp);
        }
        return ans;
    }
};