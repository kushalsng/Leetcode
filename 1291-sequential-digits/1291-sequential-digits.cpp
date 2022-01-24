class Solution {
private:
    typedef long long ll;
    ll countdig(ll num){
        ll c=0;
        while(num>0){
            num /= 10;
            c++;
        }
        return c;
    }
    ll leastSD(ll dig){
        ll num = 0;
        for(ll i = 1; i<=dig; i++){
            num = num*10 + i;
        }
        return num;
    }
    ll nextSD(ll a){
        ll b = 0;
        if(a % 10 == 9){
            int dig = countdig(a);
            b = leastSD(dig + 1);
            return b;
        }
        for(ll i = 0; a > 0; i++){
            int r = a % 10, x = pow(10, i);
            b += (r+1) * x;
            a /= 10;
        }
        return b;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        ll ldig= countdig(low);
        vector<int> v;
        ll num = leastSD(ldig);
        while(num < low) num = nextSD(num);
        if(num > high) return v;
        
        
        for(int i = num; i<= high; i = nextSD(i)){
            v.push_back(i);
        }
        return v;
    }
};