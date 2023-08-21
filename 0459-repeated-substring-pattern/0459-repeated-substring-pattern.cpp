class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=0; i<(s.length()/2); i++)
        {
            int j=0;
            string temp="";
            temp=s.substr(0,i+1);
            string res="";
            while(j<=s.length())
            {   
                res=res+temp;
                if(res.length()==s.length() && res==s)
                {
                    return true;
                }
                int k=res.length();
                string p=s.substr(0,k);
                if(p!=res)
                {
                    break;
                }
                j=k;

            }
        }
        return false;
    }
};