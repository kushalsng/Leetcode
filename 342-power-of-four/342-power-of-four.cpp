class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if((n & n-1) == 0){
            if(__builtin_popcount(n-1) %2 == 0) return true;
        }
        return false;
    }
};