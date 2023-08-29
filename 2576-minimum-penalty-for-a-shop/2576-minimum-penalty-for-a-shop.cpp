class Solution {
public:
   int bestClosingTime(string customers) {
        int n=customers.size();
        int ind=-1;
        int maxi=0;
        int score=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') score++;
            else score--;
            if(score>maxi){
                maxi=score;
                ind=i;
            }
        }
        return ind+1;
    }
};