class Solution {
public:
    int addDigits(int num) {
        int sum =0;
        int i=0;
        while(i<10 && num > 0){
            sum += num%10;
            i++;
            num /= 10;
        }
        int ans = (sum %10) + (sum % 100)/10;
        if(ans >9)ans = (ans %10) + (ans %100)/10;
        return ans;
    }
};