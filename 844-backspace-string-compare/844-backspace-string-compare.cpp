class Solution {
public:
    void process(string &s){
        int n= s.size();
        int i=0;
        while(i<n){
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
        // cout<<s<<" ";
        process(t);
        // cout<<t<<" ";
        return s == t;
    }
};