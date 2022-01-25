class Solution {
public:
    void check(stack<char> &s, char c){
        if(s.empty()){
            s.push(c); return;
        }
        if(s.top() == '(' && c == ')') s.pop();
        else if(s.top() == '{' && c == '}') s.pop();
        else if(s.top() == '[' && c == ']') s.pop();
        else s.push(c);
    }
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size(); i++){
            check(stack, s[i]);
        }
        return stack.empty();
    }
};