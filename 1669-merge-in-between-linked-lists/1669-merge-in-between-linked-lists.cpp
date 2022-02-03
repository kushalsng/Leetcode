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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1 = list1, *t1 = list1;
        ListNode* h2 = list2 , * t2 = list2;
        
        while(t2->next) t2 = t2->next;
        int ct = 1;
        while(ct < a){
            h1 = h1->next;
            ct++;
        }
        t1 = h1;
        while(ct <= b){
            t1 = t1->next;
            ct++;
        }
        t1 = t1->next;
        
        h1->next = h2;
        t2->next = t1;
        
        return list1;
    }
};