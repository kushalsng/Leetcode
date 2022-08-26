class Solution {
public:
    string sorts(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = sorts(n);
        for(int i=0; i<30; i++){
            if(s == sorts((1<<i))) return true;
        }
        return false;
    }
};