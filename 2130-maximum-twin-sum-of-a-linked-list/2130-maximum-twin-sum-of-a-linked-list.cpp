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
    typedef long long ll;
    ListNode* ReverseList(ListNode* curr, ListNode* prev, ListNode* next){
        if(!curr) return prev;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr)next = curr->next;
        return ReverseList(curr, prev, next);
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* tail = ReverseList(slow->next, NULL, slow->next->next);
        slow->next = NULL;
        slow = head;
        ll ans = 0;
        while(slow && tail){
            ans = max<long long>(ans, slow->val + tail->val);
            slow = slow->next;
            tail = tail->next;
        }
        return ans;
    }
};