class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
//         int n=nums.size();
//         int s=0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             s+=nums[i];
//         }
//         int p=0;
//         // for(int i=0; i<nums.size(); i++)
//         // {
//         //     p+=(nums[i]*nums[i]);
//         // }

//         int ss=(n*(n+1))/2;
//         // int pp=(n*(n+1)*(2*n+2))/6;

// // int k=ss-s;
// // int j=pp-p;

//       return ss-s;

int res=0;
for(int i=0; i<nums.size(); i++)
{
    res^=i;
    res^=nums[i];
}
return res^=nums.size();

    }
};