class Solution {
private:
   int getlength(int x){
       if(x==0){
           return 1;
       }
       int length=0;
       while(x!=0){
           x=x/10;
           length++;
       }
       return length;
   }

public:
    bool isPalindrome(int x) {
        int len=getlength(x);
        int n=x;
        long long ans=0;
        int rem=0;

        if(x<0){
            return false;
        }

        for(int i=0;i<len;i++){
           rem=x%10;
           ans=ans+rem*pow(10,len-i-1);
           x=x/10;
        }

        
        if(ans==n){
            return true;
        }
        return false;
    }
};