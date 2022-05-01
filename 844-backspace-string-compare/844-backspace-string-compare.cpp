class Solution {
public:
    void process(string &s){
        int i=0;
        while(i<s.size()){
            if(s[i] == '#'){
                if(i==0)s.erase(s.begin()+i);
                else{
                    s.erase(s.begin()+i);
                    i--;
                    s.erase(s.begin()+i);
                }
            }else i++;
        }
    }
    bool backspaceCompare(string s, string t) {
        process(s);
        process(t);
        return s == t;
    }
};