/* Merge Two Sorted Linked list

Time Complexity : O(N+M)  where N = size of first linked list , M = size of second linked list
Space Complexity : O(1)

*/

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL)
    {
        return second;
    }
    if(second == NULL)
    {
        return first;
    }

    if(first->data > second->data)
    swap(first,second);

    Node<int>* result = first;

    while(first && second)
    {
        Node<int>* temp = NULL;

        while(first && first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }

        temp->next = second;
        swap(first,second);
    }

    return result;

}