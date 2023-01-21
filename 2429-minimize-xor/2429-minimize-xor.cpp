class Solution {
public:
  int check(int n)
  {
      int sum = 0;
      while(n>0)
      {
          if((n&1) == 1)
          {
              sum++;
          }
          n = n>>1;
      }
      return sum;
  }
    
    int minimizeXor(int num1, int num2) {
        long long int setBits1 = check(num1);
        long long int setBits2 = check(num2);
        long long int x = num1;
        if(setBits1 == setBits2)
        {
           return x; 
        }
        
        long long int setBitsx = check(x);
        if(setBitsx < setBits2)
        {
            while(setBitsx<setBits2)
            {
                x = x|(x+1);
                setBitsx = check(x);
            }
        }
        else
        {
            while(setBitsx>setBits2)
            {
                    x = x&(x-1);
                setBitsx = check(x);
            }
        }
        return x;
    }
};