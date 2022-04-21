/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(int c1,int c2, ListNode *headA, ListNode *headB){
        ListNode* t1 = headA, *t2 = headB;
        int diff = abs(c1-c2);
        while(diff--)t1 = t1->next;
        while(t1 != t2 && t1 != NULL)t1 = t1->next,t2 = t2->next;
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0;
        ListNode* t1 = headA, *t2 = headB;
        while(t1)c1++, t1 = t1->next;
        while(t2)c2++, t2 = t2->next;
        if(c1>c2)return solve(c1,c2,headA,headB);
        if(c2>c1)return solve(c2,c1,headB,headA);
        else{
            t1 = headA, t2=headB;
        while(t1 != t2 && t1 != NULL)t1 = t1->next,t2 = t2->next;
        return t1;
        }
    }
};