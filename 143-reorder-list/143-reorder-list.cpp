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
    int getSize(ListNode* head){
        if(!head) return 0;
        else if(!head->next) return 1;
        int count =0;
        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverseList(ListNode* curr, ListNode* prev, ListNode* next){
        if(!curr) return prev;
        
        curr->next = prev;
        prev = curr;
        if(next)curr = next;
        else curr = NULL;
        if(curr)next = curr->next;
        else next = NULL;
        
        return reverseList(curr, prev, next);
    }
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return;
        int n = getSize(head);
        ListNode* slow= head, *fast = head;
        while(fast && fast->next){
            slow = slow->next; 
            fast = fast->next->next;
        }
        // cout<<slow->val<<" ";
        ListNode* tail = reverseList(slow->next, slow, slow->next->next);
        slow->next = NULL;
        ListNode* h = head, *t = tail, *ognext = head->next;
        
        if(fast){
            while(ognext){
                tail = t->next;
                h->next = t;
                t->next = ognext;
                t = tail;
                h = ognext;
                ognext = ognext->next;
            }
        } else {
            while(ognext->next){
                tail = t->next;
                h->next = t;
                t->next = ognext;
                t = tail;
                h = ognext;
                ognext = ognext->next;
            }
        }
        
    }
};