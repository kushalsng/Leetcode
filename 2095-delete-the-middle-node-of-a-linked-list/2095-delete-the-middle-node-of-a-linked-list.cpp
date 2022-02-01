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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        int size = getSize(head);
        ListNode* slow = head, *fast = head;
        int ct=1;
        int mid = size / 2;
        if(size %2==0){
            while(fast && ct<mid){
                slow = slow->next;
                fast = fast->next->next;
                ct++;
            }
        } else {
            while(fast->next && ct<mid){
                slow = slow->next;
                fast = fast->next->next;
                ct++;
            }
        }
        if(slow->next->next)slow->next = slow->next->next;
        else slow->next = NULL;
        return head;
    }
};