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
    int length(ListNode* head){
        int cnt=0;
        ListNode* temp = head;
        while(temp)cnt++,temp = temp->next;
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)return head;
        int n = length(head);
        ListNode * neww = new ListNode(0);
        neww->next = head;
        ListNode* prev = neww, *curr, *nxt;
        while(n >=k){
            curr = prev->next;
            nxt = curr->next;
            for(int i=1; i<k; i++){
                curr->next = nxt->next;
                nxt->next= prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            n -= k;
        }
        return neww->next;
    }
};