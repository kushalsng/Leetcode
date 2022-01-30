/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> lists(k, NULL);
        if(!head) return lists;
        
        int n=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        vector<int> v(k, 1);
        
        int nmodk = n % k;
        for(int i=0; i< k; i++){
            if(k < n){
                v[i] = n / k;
                if(nmodk>0){
                    v[i]++;
                    nmodk--;
                }
            } else {
                if(i>=n) v[i] = 0;
            }
        }
        // for(auto it: v) cout<< it<< " ";
        
        int ind=0;
        for(int i = 0; i< v.size() && v[i] !=0 && head; i++){
            ListNode* h = head, *t = head;
            int len = 1;
            
            while(len < v[i] && t->next){
                t= t->next;
                len++;
            }
            head = t->next;
            t->next = NULL;
            lists[ind] = h;
            ind++;
        }
        // if(ind < k-1){
        //     while(ind < k){
        //         lists[ind] = NULL;
        //     }
        // }
        
        return lists;
    }
};