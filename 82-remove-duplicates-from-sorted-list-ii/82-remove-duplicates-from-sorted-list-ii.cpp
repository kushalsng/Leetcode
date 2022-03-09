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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ioi = new ListNode(101);
        ioi->next = head;
        head = ioi;
        
        ListNode* t1 = head, *t2= head->next;
        int data = 101;
        
        while(t2){
            if(t2->next){
                if(t2->val != t2->next->val && t2->val != data){
                    t1->next = t2;
                    t1= t1->next;
                    data = t2->val;
                    
                } else {
                    data = t2->val;
                }
            }else {
                if(t2->val == data){
                    t1->next = NULL;
                }else {
                    t1->next = t2;
                }
            }
            t2 = t2->next;
        }
        
        
        head = head->next;
        return head;
    }
};