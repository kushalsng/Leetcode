class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> v;
        for(auto c: s) {
            if(v.empty()) v.push_back(c);
            else if(v.back() == '(' && c == ')' ) v.pop_back();
            else v.push_back(c);
        }
        return v.size();
    }
};