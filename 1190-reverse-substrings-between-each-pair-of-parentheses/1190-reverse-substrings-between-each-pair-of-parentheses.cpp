class Solution {
public:
//     string reverseParentheses(string s) {
//         string ans ="";
//         stack<char> stk;
//         for(auto c: s){
//             if(stk.empty() && c == '(') stk.push(c), ans += '_';
//             // else if(!stk.empty() && stk.top() == '(' && c == '(') ;
//             else if(c== ')'){
//                 while(stk.top() != '(')stk.pop();
//                 stk.pop();
//                 ans += '_';
//                 int i=0, j= ans.size()-1;
//                 while(ans[i] != '_')++i;
//                 while(ans[j] != '_')--j;
//                 ++i,--j;
//                 while(i<j) swap(ans[i], ans[j]);

//             }else ans += c;
//         }
//         while()
//         return ans;
//     }
    string reverseParentheses(string str) {
        string ans ="";
        stack<char> s;
        queue<char> q;
        for(auto c : str){
            if(c == '(') s.push('#');
            else if(c== ')'){
                while(s.top() != '#'){
                    q.push(s.top());
                    s.pop();
                }
                s.pop();
                while(!q.empty()){
                    s.push(q.front());
                    q.pop();
                }
            } else s.push(c);
        }
        while(!s.empty()){
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};