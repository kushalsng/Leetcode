class Solution {
public:
    bool isPalindrome(int x) {
        
        //negative numbers are not palindrome
        if(x<0) return false;
        
        
        int n = 0, a = x;       //n stores the number of digits in x
        while(a != 0){
            n++;
            a /= 10;
        }
        
        //single digit numbers are palindrome
        if(n == 1) return true;
        
        int y=0, u=1;           
        int len = n/2;
        
        //this loop is saving one half of x in y in reverse order
        for(int i = 0; i < len; i++){
            if(i>0) u = 10;
            y= y*u + (x % 10);
            x /= 10;
        }
        
        //if number of digits were odd,
        //we have to remove middle element
        if(n % 2 != 0) x /= 10;
        
        //if number is palindrome, x and y should be equal
        return x == y ? true : false;
    }
};