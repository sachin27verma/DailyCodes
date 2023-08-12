class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int>m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }

        vector<int >ans;
  int flag=0;

  for(int i=0; i<nums.size(); i++)
  {
      if(flag==0)
      {
          auto result=m.find(target-nums[i]);


          
      if(result!=m.end() )
      {
          if(target-nums[i]==nums[i] && result->second>1)
          {
               flag=1;
          ans.push_back(i);
          target=target-nums[i];
          }
          
        else if(target-nums[i]!=nums[i]) { 
            flag=1;
          ans.push_back(i);
          target=target-nums[i];
            
        }
          
          
          
      }
      
      }
      else 
      {
          if(nums[i]==target)
          {
              ans.push_back(i);
          }
      }
  }

  return ans;


    }
};