/** Problem : Reverse a LinkedlIst 
Time COmplexity : O(N)
Space Complexity : O(1)
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
    ListNode* newNode = NULL;

    ListNode* reverseList(ListNode* head) {
        ListNode* Next;
        while(head != NULL)
        {
        Next = head->next;
        head->next = newNode;
        newNode = head;
        head = Next;
        }
        return newNode;
    }
};
