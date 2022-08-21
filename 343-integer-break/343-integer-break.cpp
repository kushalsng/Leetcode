class Solution {
public:
    int integerBreak(int n) {
        if(n<4)return n-1;
        int div = n/3;
        int ans= 0;
        if(n%3 == 1){
            return pow(3,div-1)*4;
        }
        else if(n%3 == 2)return pow(3,div)*2;
        else return pow(3,div);
    }
};