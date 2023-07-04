/* Problem : Find Intersection Of Two linked list

Time Complexity : O(2*max(length of list1,length of list2))
Space Complexity : O(1)
*/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headA:d1->next;
        d2 = d2 == NULL? headB:d2->next;
    }
    
    return d1;
    }
};