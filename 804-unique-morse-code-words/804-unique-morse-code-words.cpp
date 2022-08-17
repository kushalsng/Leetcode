class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> us;
        for(auto s: words){
            string str ="";
            for(auto c: s){
                str += morse[c-'a'];
            }
            us.insert(str);
        }
        return us.size();
    }
};