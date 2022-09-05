/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let t1 = headA, t2 = headB;
    let c1=0,c2=0;
    while(t1)c1++, t1 = t1.next;
    while(t2)c2++, t2 = t2.next;
    let diff = Math.abs(c1-c2);
    t1 = headA, t2 = headB;
    if(c1>c2){
        while(diff--)t1 = t1.next;
    }else while(diff--)t2 = t2.next;
    while(t1 && t2 && t1 != t2) t1=t1.next, t2 = t2.next;
    return t1;
};