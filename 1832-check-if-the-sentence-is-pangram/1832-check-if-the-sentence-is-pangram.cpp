class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> mp;
        for(auto x: sentence)mp.insert(x);
        return mp.size() == 26;
    }
};