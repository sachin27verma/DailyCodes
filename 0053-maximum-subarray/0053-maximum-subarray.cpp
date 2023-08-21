class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    //     int res=0;
    //     int sum=0;
    //     int count=0;
    //    int minn=INT_MIN;
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         if(nums[i]<0)
    //         {
    //             count++;
    //             minn=max(minn,nums[i]);
    //         }
    //         sum+=nums[i];
    //         if(sum<0)
    //         {
    //             sum=0;
    //         }
    //         res=max(sum,res);
            
    //     }
    //     if(count==nums.size())
    //     {
    //         return minn;
    //     }
    //     else
    //     return res;
    int sum = 0;
       int maxSum = INT_MIN;
       for(int  i =0;i<nums.size();i++){
           sum+=nums[i];
           maxSum =  max(maxSum,sum);
           if(sum<0){
               sum = 0;
           }
       }
       return maxSum;
    
    }


    

    




};