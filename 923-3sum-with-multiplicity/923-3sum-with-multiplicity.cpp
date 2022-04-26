class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, long long> mp;
        for(auto x: arr)mp[x]++;
        
        long long ans=0;
        for(auto it1=mp.begin(); it1 != mp.end(); it1++){
            for(auto it2=mp.begin(); it2 != mp.end(); it2++){
                int el1 = it1->first, el2 = it2->first;
                int el3 = target - el1 - el2;
                if(mp.find(el3) != mp.end()){
                    long long fx1 = mp[el1];
                    long long fx2 = mp[el2];
                    long long fx3 = mp[el3];
                    
                    if(el1 == el2 && el2 == el3){
                        ans += ((fx1)*(fx1-1)*(fx1-2))/6;
                    }else if(el1 == el2 && el2 != el3){
                        ans += ((fx1 * (fx1-1))/2) *fx3;
                    }else if(el1<el2 && el2<el3){
                        ans += fx1 *fx2*fx3;
                    }
                }
                ans %= 1000000007;
            }
        }
        return (int) ans;
    }
};