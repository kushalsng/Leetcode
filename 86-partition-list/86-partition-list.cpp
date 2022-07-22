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
    ListNode* partition(ListNode* head, int x) {
        ListNode* grt = NULL, *t2 = NULL, *prev = NULL, *curr = head;
        while(curr){
            if(curr->val < x){
                prev = curr;
                curr = curr->next;
            }else{
                if(!t2){
                    t2 = curr;
                    grt = t2;
                }
                else{
                    t2->next = curr;
                    t2 = t2->next;
                }
                
                if(prev){
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                }else{
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    head = temp;
                }
            }
        }
        if(prev) prev->next = grt;
        else head = grt;
        return head;
    }
};