class Solution {
private:
int getIntegerLength(int x) {
    if (x == 0) {
        return 1;
    }
    
    int length = 0;
    while (x != 0) {
        x = x / 10;
        length++;
    }
    
    return length;
}
public:
    int reverse(int x) {
        int len=getIntegerLength(x);
        long ans=0;
        for(int i=0;i<len;i++){
        
        int last_digit=x%10;
        x=x/10;
        ans = ans + last_digit *pow(10, len - i - 1);
        }

        if(ans>INT_MAX || ans<INT_MIN) {
        return 0; // check range if it is outside the range then return 0
        }
        return ans;

    }
}; 


