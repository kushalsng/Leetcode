class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n%3==0) n/=3;
        if(n<3) {
            if(n==2)return false;
            return true;
        }
        return false;
    }
};