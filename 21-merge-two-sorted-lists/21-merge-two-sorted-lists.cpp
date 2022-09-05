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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* a = list1, *b = list2, *head, *tail;
        head = (a->val < b->val) ? list1 : list2;
        tail = (a->val < b->val) ? list1 : list2;
        
        head == a ? a = a->next : b = b->next;
        
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                tail = tail->next;
                a = a->next;
            }else{
                tail->next = b;
                tail = tail->next;
                b = b->next;
            }
        }
        if(a){
            tail->next = a;
        }
        if(b){
            tail->next = b;
        }
        return head;
    }
};