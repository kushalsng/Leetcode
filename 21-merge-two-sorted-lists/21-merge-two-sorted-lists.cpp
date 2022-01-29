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
    ListNode* mergeSortedList(ListNode* headA, ListNode* headB){
    if(!headA && !headB);
    if(!headA) return headB;
    if(!headB) return headA;
    ListNode* i = headA, *j = headB;
    ListNode* prev = NULL;
    ListNode* next = i->next;
    
    while(j){
        if(i->val < j->val){
            while(i->next){
                if(i->next->val <= j->val){
                    prev = i; i = i->next; next = i->next;
                }else break;
            }
        }

        if(j->val <= i->val){
            if(i == headA){
                headB = headB->next;
                j->next = i;
                headA = j;
                prev = j;
                j = headB;
                next = i->next;
            } else {
                prev->next = j;
                headB = headB->next;
                j->next = i;
                prev = prev->next;
                j = headB;
            }
        } else {
            i->next = j;
            headB = headB->next;
            j->next = next;
            prev = i;
            i = j;
            next = i->next;
            j = headB;
        }
    }
    return headA;
}

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int s1 =0, s2=0; 
        ListNode* temp = list1;
        while(temp){
            // cout<<temp->val<<" ";
            temp = temp->next;
            s1++;
        }
        // cout<<endl;
        temp = list2;
        while(temp){
            // cout<<temp->val<<" ";
            temp = temp->next;
            s2++;
        }
        // cout<<endl;
        // ListNode* res = NULL;
        return s1 >= s2 ? mergeSortedList(list1,list2) : mergeSortedList(list2,list1);
    }
};