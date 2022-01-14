class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = 0, a = x;
        while(a != 0){
            n++;
            a /= 10;
        }
        if(n == 1) return true;
        
        int y=0, u=1;
        int len = n/2;
        
        for(int i = 0; i < len; i++){
            if(i>0) u = 10;
            y= y*u + (x % 10);
            x /= 10;
        }
        
        if(n%2 !=0) x /= 10;
        
        return x == y ? true : false;
    }
};