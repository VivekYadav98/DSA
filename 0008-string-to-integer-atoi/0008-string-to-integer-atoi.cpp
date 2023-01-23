class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int i=0;
        int n = s.length();
        while(i<n && s[i] == ' ')
        {
            i++;
        }
        bool flag = true;
        if(s[i] == '-')
        {
            flag = false;
            i++;
        }
        
        if(s[i] == '+' && flag == true)
        {
            i++;
        }
        
        while(i<n && s[i] >= '0' && s[i] <= '9')
        {
                  ans=ans*10+(s[i]-'0');//convertion from char to interger 
               if(ans>INT_MAX && flag==true)
               {//check whether a is greater then INTMAX(2^31-1);
                    return INT_MAX;
               }
               if(-ans<INT_MIN && flag==false)
               {
                   //check for INTMIN(-2^31);
                    return INT_MIN;
               }
                i++;
        }
       
       if(flag == false)
       {
           return -ans;
       }
       return ans;
    }
};