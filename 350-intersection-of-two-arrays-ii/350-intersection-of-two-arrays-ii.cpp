class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1,m2;
        vector<int> ans;
        for(auto x: nums1) m1[x]++;
        for(auto x: nums2) m2[x]++;
//         for(auto it1=m1.begin(), it2= m2.begin(); it1 != m1.end() || it2 != m2.end();){
//             if(it1 != m1.end())cout<<it1->first<<":"<<it1->second<<endl, ++it1;
//             if(it2 != m2.end())cout<<it2->first<<":"<<it2->second<<endl, ++it2;
//             cout<<" \n";
//         }
//         if(size(m1) >= size(m2)){
//             m1.clear();
//             for(auto x: nums1){
//                 if(m2.find(x) != m2.end()) m1[x]++;
//             }
//         }else{
//             cout<<"in else\n";
//             m2.clear();
//             cout<<m2.size();
//             for(auto x: nums2){
//                 if(m1.find(x) != m1.end()) m2[x]++;
//             }
//             cout<<m2.size();

//         }
        // cout<<"\nAFTER\n";
        // for(auto it1=m1.begin(), it2= m2.begin(); it1 != m1.end() || it2 != m2.end();){
        //     if(it1 != m1.end())cout<<it1->first<<":"<<it1->second<<endl, ++it1;
        //     if(it2 != m2.end())cout<<it2->first<<":"<<it2->second<<endl, ++it2;
        //     cout<<" \n";
        // }
        for(auto it1=m1.begin(), it2= m2.begin(); it1 != m1.end() && it2 != m2.end();){
            cout<<it1->first<<" "<<it2->first<<", ";
            if(it1->first < it2->first)++it1;
            else if(it2->first < it1->first) ++it2;
            else{
                int diff = min(it1->second, it2->second);
                while(diff--)ans.push_back(it1->first);
                ++it1, ++it2;
            }
        }
        return ans;
    }
};