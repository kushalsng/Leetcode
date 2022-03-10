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
    
    //Function to insert a value at end of the list
    ListNode* insertAtEnd(ListNode* l, int val){
        ListNode* n = new ListNode(val);
        if(!l) return n;
        ListNode* temp = l;
        while(temp->next) temp = temp->next;
        temp->next = n;
        return l;
    }
    
    //Function to add remaining list to l3 in case of unequal size
    ListNode* addRemainList(ListNode* l, int* aux, ListNode* l3){
        while(l){
            int sum = l->val + *aux;
            int uni = sum % 10;
            l3 = insertAtEnd(l3, uni);
            *aux = sum / 10;
            l = l->next;
        }
        return l3;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        int aux = 0;     //aux keeps the carry of sum
        
        //loop ends if any of the list exhausts
        while(l1 && l2){
            int sum = l1->val + l2->val + aux;      // sum var sums both vals and aux
            int uni = sum % 10;       
            l3 = insertAtEnd(l3, uni);      //insert only unit place digit of sum var
            aux = sum / 10;       //aux keeps 10th place digit (if any)
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //this if block handles situation if any of the list is remaining
        if(l1){
            l3 = addRemainList(l1, &aux, l3);       //sending reference of aux for future use
        }else if(l2){
            l3 = addRemainList(l2, &aux, l3);
        }
        
        //if aux have a value then it is added at the end of the list.
        if(aux){
            l3 = insertAtEnd(l3, aux);
        }
        return l3;
    }
};