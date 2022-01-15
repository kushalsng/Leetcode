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
//     ListNode* logic(ListNode* head, int l, int r, int c, vector<int> v, bool isPushed){
//         ListNode* temp = head;
        
//         while(c<l){
//             temp = temp->next;
//             c++;
//         }
//         while(c<=right){
//             if(isPushed){
//             temp->val = v[v.size()-1];
//             v.pop_back();
//             }else {
//                  v.push_back(temp->val);
//             }
//             temp = temp->next;
//              c++; 
//         }
        
//         return head;
//     }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* temp = head;
        int c = 1;
        while(c<left){
            temp = temp->next;
            c++;
        }
        int aux = c;
        while(c<=right){
            v.push_back(temp->val);
            temp = temp->next;
            c++;
        }
        temp = head;
        c= 1;
        while(c<left){
            temp = temp->next;
            c++;
        }
        
        while(c<=right){
            temp->val = v[v.size()-1];
            v.pop_back();
            c++;
            temp = temp->next;
        }
        
        return head;
    }
};