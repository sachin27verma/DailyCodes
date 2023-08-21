class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int,int>m;
        // for(auto i:nums)
        // {
        //     m[i]++;
        // }
        // for(auto i:m)
        // {
        //     if(i.second>=2)
        //     {
        //         return true;
        //     }
        // }
        // return false;
        sort(nums.begin(),nums.end());
       for(int i=1; i<nums.size(); i++)
       {
           if(nums[i]==nums[i-1])
           {
               return true;
           }
       }
       return false;
    }
};