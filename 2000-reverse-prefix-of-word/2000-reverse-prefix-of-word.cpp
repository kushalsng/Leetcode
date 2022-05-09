class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.size() && word[i] != ch)i++;
        if(i<word.size())reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};