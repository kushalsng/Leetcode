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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL,*temp;
        if(lists.size()==0)return head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto n: lists){
            while(n){
                // cout<<n->val<<" ";
                pq.push({n->val,n});
                n = n->next;
            }
        }
        if(!pq.empty()){
            head =pq.top().second;
            temp=head;
            pq.pop();
        }
        while(!pq.empty()){
            temp->next = pq.top().second;
            pq.pop();
            temp = temp->next;
        }
        return head;
    }
};