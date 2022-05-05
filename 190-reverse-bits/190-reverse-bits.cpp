class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int i=31,j=0;
        while(i>=0){
            if((n&(1<<i)))ans |= (1<<j);
            i--,j++;
        }
        return ans;
    }
};