/* Problem : Reverse Linked List in Group Of k

Time Complexity : O(N)
Space Complexity : O(1)

*/
int LinkedListLength(Node *head){
	int count=0;
	while(head){
		++count;
		head = head->next;
	}
	return count;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL || head->next==NULL) return head;

	int length = LinkedListLength(head);

	Node *dummy = new Node(0);
	dummy->next = head;
	Node *prev = dummy;
	Node *curr,*nex;
	int i=0;

	while(length>0 && i<n){
		if(b[i]==0){
			i++;
			continue;
		};
		curr = prev->next;
		nex = curr->next;

			if(length>=b[i]){
				for(int j=1;j<b[i];j++){
				curr->next = nex->next;
				nex->next = prev->next;
				prev->next = nex;
				nex = curr->next;
			    }

				prev = curr;
				length-=b[i];
				i++;
			}

			else if(length<b[i]){
				for(int j=1;j<length;j++){
				curr->next = nex->next;
				nex->next = prev->next;
				prev->next = nex;
				nex = curr->next;
			    }

				prev = curr;
				length-=b[i];
				i++;
			}
			
		}

		return dummy->next;
	}
