class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> a(encoded.size() + 1);
        a[0] = first;
        for(int i = 1; i<encoded.size() + 1; i++){
            a[i] = a[i-1] ^ encoded[i-1];
        }
        return a;
    }
};