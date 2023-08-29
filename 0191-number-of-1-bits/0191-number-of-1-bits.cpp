class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int flag=1;
    while(n)
        {

            
            count++;
            
            n=n&(n-1);


        }
      
        return count;
    }
};