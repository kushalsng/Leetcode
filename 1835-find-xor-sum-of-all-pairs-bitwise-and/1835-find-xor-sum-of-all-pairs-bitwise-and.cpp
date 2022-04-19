class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m1,m2;
        int ans=0;
        for(auto x: arr1)m1[x]++;
        for(auto x: arr2)m2[x]++;
        
        // for(auto it = m1.begin(); it != m1.end();){
        //     if(it->second%2==0) m1.erase(it->first);
        //     else it++;
        // }
        // for(auto it = m2.begin(); it != m2.end();){
        //     if(it->second%2==0) m2.erase(it->first);
        //     else it++;
        // }
        for(auto it1 = m1.begin(); it1 != m1.end();it1++){
            if(it1->second%2){
                for(auto it2= m2.begin(); it2 != m2.end();it2++){
                    if(it2->second%2){
                        if(it2->first == it1->first) ans ^= it2->first;
                        else ans ^= (it2->first & it1->first);
                    }
                }
            }
        }
        // for(auto it = m2.begin(); it != m2.end();it++){
        //     cout<<it->first<<": "<<it->second<<", ";
        // }
        return ans;
    }
};