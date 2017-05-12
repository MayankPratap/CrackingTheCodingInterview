// Check Palindrome: Whether Linked list is palindrome

#include<bits/stdc++.h>
using namespace std;

struct Node{
	
	int data;
	Node* link;

};

Node* Insert(Node* head,int val){    // Insertion at end

	Node* temp=new Node();

	temp->data=val;
	temp->link=NULL;

	if(head==NULL){   // empty list

		head=temp;
		return head;
	}

	Node* p=head;

	while(p->link!=NULL){

		p=p->link;
	}

	p->link=temp;

	return head;

}

void Print(Node* head){

	Node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<" ";
		temp=temp->link;
	}

}

Node* get_middle_node(Node* head){

	if(head==NULL || head->link==NULL){

		return head;

	}

	Node *slow_ptr=head,*fast_ptr=head->link;

	while(fast_ptr!=NULL && fast_ptr->link!=NULL){

		slow_ptr=slow_ptr->link;
		fast_ptr=fast_ptr->link->link;

	}

	return slow_ptr;

}

int get_length(Node* head){

	int cnt=0;

	while(head!=NULL){

		cnt+=1;
		head=head->link;

	}

	return cnt;
}

Node* reverseList(Node* head){

	Node *prev=NULL,*current=NULL,*next=NULL;

	current=head;

	while(current!=NULL){

		next=current->link;
		current->link=prev;

		prev=current;  
		current=next;

	}

	head=prev;

	return head;

}

bool checkPalindrome(Node *head){

	if(head==NULL || head->link==NULL) // empty list or list with one node
		return true;

	// Generalised version did not work for 2 nodes because 2nd half was getting nulled.
	//  which caused Segmentation Fault.

	if(head->link->link==NULL){  // For two nodes 

		if(head->data==head->link->data)
			return true;
		else 
			return false;

	}

	Node *first_half=head,*middle_node=NULL,*second_half=NULL;
	middle_node=get_middle_node(head);
	int length=get_length(head);  // length of linked list

	// In case of even number of nodes: There are two nodes that can claim to represent middle this will give me the first one.
	// In case of odd number of nodes: The clear middle

	// Now I am going to split my linked list in two halves

	// Preparing first half
	Node *p=head,*q;
	while(p!=middle_node && p->link!=middle_node){

		p=p->link;

	}

	if(length%2==0){

		p=p->link;
		second_half=p->link;
		p->link=NULL;

	}

	else{

		second_half=p->link->link;
		p->link=NULL;

	}

	

	// Preparing second half


	
	// Now reversing second half

	second_half=reverseList(second_half);

	// Now comparing first half and reversed second half

	p=first_half,q=second_half;

	bool check=true;

	while(p!=NULL && q!=NULL){

		if(p->data!=q->data){

			check=false;
			break;

		}

		p=p->link;
		q=q->link;


	}

	// Now joining back first half and original second half

	second_half=reverseList(second_half);

	p=first_half;
	q=second_half;

	while(p->link!=NULL){

		p=p->link;

	}

	if(length%2==0){

		p->link=second_half;

	}

	else{

		p->link=middle_node;
		middle_node->link=second_half;

	}


	return check;



}

int main(){

	Node* head;
	head=NULL;

	head=Insert(head,1);
	head=Insert(head,1);
	head=Insert(head,1);
	head=Insert(head,1);
	head=Insert(head,1);

	//cout<<get_middle_node(head)->data<<"\n";

	cout<<checkPalindrome(head)<<"\n";

	return 0;

}