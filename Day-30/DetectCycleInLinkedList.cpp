/* Linked List Cycle Detection using Hare and Tortoise algorithm

Time Complexity : O(N)
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast = head;
        bool flag = false;
        while(fast && fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                fast = head;
                flag = true;
                break;
            }
        }
        if(flag){
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        }
        else
        {
            return NULL;
        }

        return fast;
    }
};
