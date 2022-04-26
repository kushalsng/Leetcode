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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp;
        int count=0, mid =0;
        temp = head;
        
        while(temp){
            count++;
            temp = temp->next;
        }
        count % 2 != 0 ? mid = count/2 : mid = (count + 1) /2;
        cout<<mid<<endl;
        int count2=0;
        temp = head;
        while(count2<mid && temp){
            count2++;
            temp = temp->next;
        }
        return temp;
    }
};