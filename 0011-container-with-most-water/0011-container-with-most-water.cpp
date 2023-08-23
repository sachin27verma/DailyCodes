class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        int maxsum=0;
        int maxxheight=0;
//         for(int i=height.size()-1; i>0; i--)
//         {
//             for(int j=0; j<height.size(); j++)
//             {
//                             int p=min(height[j],height[i]);
//                 int area=p*(i-j);
//                 maxsum=max(area,maxsum);

//             }
            
//         }
        while(i<j)
        {
            // int p=min(height[i],height[j]);
            // int area=p*(j-i);
            if(height[i]>height[j])
            {
                maxsum=max(maxsum,height[j]*(j-i));
                j--;
            }
            else
            {
                 maxsum=max(maxsum,height[i]*(j-i));
                i++;
                
            }
        }
        
        return maxsum;
    }
};