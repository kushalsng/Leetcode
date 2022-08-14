class Solution {
public:
    int bton(string s){
        int num = 0;
        int ind=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != '0')num += pow(2,ind);
            ind++;
        }
        return num;
    }
    string ntob(int n, int sz){
        string s;
        for (int i = sz-1; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                s += "1";
            else
                s += "0";
        }
        return s;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> mp;
        int n = nums.size();
        for(auto s : nums){
            mp.insert(bton(s));
        }
        int i=0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            // cout<<i<<" ";
            if(i != *it){
                break;
            }
            i++;
        }
        // cout<<ntob(2,2)<<" ";
        return ntob(i,n);
    }
};