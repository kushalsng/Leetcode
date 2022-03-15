class Solution {
public:
    string minRemoveToMakeValid(string str) {
        stack<pair<char,int>> s;
        int i=0;
        while(i<str.size()){
            if(str[i] == ')') {
                if(s.empty()){
                    str.erase(str.begin()+i);
                }
                else
                    s.pop(), i++;
            }
            else {
                if(str[i] == '(') s.push({str[i], i});
                i++;
            }
        }
        while(!s.empty()) {
            str.erase(str.begin() + s.top().second);
            s.pop();
        }
        return str;
    }
};