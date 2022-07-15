class Solution {
public:
    string defangIPaddr(string s) {
        string ans ="";
        for(auto x: s){
            if(x == '.'){
                ans += "[.]";
            }else ans += x;
        }
        return ans;
    }
};