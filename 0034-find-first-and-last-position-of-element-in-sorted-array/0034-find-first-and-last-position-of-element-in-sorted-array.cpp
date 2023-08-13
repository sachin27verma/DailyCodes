class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
         long int left=-1;
        long int right=-1;
    long  int start=0; 
    long   int end=v.size()-1;
        while(start<=end)
        {
            long int mid=start + (end-start)/2;
            if(v[mid]==x)
            {
                left=mid;
                end=mid-1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
      start=0; 
     end=v.size()-1;
        while(start<=end)
        {
            long int mid=start + (end-start)/2;
            if(v[mid]==x)
            {
                right=mid;
                start=mid+1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
       vector<int>ans;
       ans.push_back(left);
       ans.push_back(right);
       return ans;
    }
};