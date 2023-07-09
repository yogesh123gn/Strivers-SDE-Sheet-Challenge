/* Problem : Flattening a Linked List
Time Complexity : O(N)
Space Complexity : O(1)
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

#define bottom child
Node* merge2sortedLL(Node* h1, Node* h2)  
{  
    // code here
    Node* head=NULL;
    if(h1==NULL&&h2==NULL){
        return head;
    }
    if(h1==NULL&&h2){
        return h2;
    }
    if(h1&&!h2){
        return h1;
    }
    Node* temp=NULL;
    if(h1->data<=h2->data){
        head=h1;
        h1=h1->bottom;
        temp=head;
    }
    else{
        head=h2;
        h2=h2->bottom;
        temp=head;
    }
    while(h1&&h2){
       if(h1->data<h2->data){
         temp->bottom=h1;
         h1=h1->bottom;
         temp=temp->bottom;
       }
       else{
         temp->bottom=h2;
         h2=h2->bottom;
         temp=temp->bottom;
       }
    } 
    if(h1){
        temp->bottom=h1;
    }
    if(h2){
        temp->bottom=h2;
    }
    return head;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flattenLinkedList(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL) return root;
   Node* temp1 = root;
   Node* temp2 = root->next;
   while(temp2){
       temp1=merge2sortedLL(temp1,temp2);
       temp2=temp2->next;
   }
   Node* temp=temp1;
   while(temp){
       temp->next=NULL;
       temp=temp->bottom;
   }
   return temp1;
}

