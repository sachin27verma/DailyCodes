class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int res=1000;
        int start=0;
        int end=letters.size()-1;
        int flag=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(letters[mid]==target)
            {
                
                start=mid+1;
                

                
               
            }
            else if(letters[mid]>target)
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        if(res==1000)
        {
            return letters[0];
        }
        
        else
        {
            return letters[res];
        }
    }
};