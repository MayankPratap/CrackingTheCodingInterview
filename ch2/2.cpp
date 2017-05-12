//  Return kth to Last in a linked list.

#include<bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;

};

Node *head;
Node *farzee;

void Insert(int val){    // Insertion at end

	Node* temp=new Node();

	temp->data=val;
	temp->link=NULL;

	if(head==NULL){   // empty list

		head=temp;
		return;

	}

	Node* p=head;

	while(p->link!=NULL){

		p=p->link;
	}

	p->link=temp;
}

/*

     This approach is iterative using two pointers and does the work in one pass.
     No need of calculating length of linked list.

     Time Complexity :- O(n) Space Complexity:- O(1)

*/

Node* returnkth(int k){   

	if(k<1){

		return farzee;

	}
	Node* second=head;
	int diff=k-1;
	Node* first=head;

	while(diff){
		first=first->link;
		diff-=1;
	}

	while(first->link!=NULL){
		second=second->link;
		first=first->link;
	}

	return second;

}

/* This approach is recursive and does not need knowing and calculating length of linked list.
	
   Time Complexity:- O(n) and Space Complexity:- O(n)

*/

Node* nthToLast(Node* head,int k,int &i){

	if(head==NULL){

		return NULL;

	}

	Node* nd=nthToLast(head->link,k,i);

	i=i+1;

	if(i==k){

		return head;

	}

	return nd;


}

Node* nthToLast(Node* head,int k){

	int i=0;  // counter to find when kth to last node has occcured
	return nthToLast(head,k,i);

}


int main(){
		
	head=NULL;

	farzee=new Node();

	farzee->data=INT_MAX;
	farzee->link=NULL;

	Insert(4);
	Insert(8);
	Insert(2);
	//Insert(6);

	int k;
	k=2;

	/*Node* node=returnkth(k);


	if(node->data==INT_MAX)
		cout<<"Please enter possible value of k\n";
	else
		cout<<node->data<<"\n";

	*/

	Node* node=nthToLast(head,k);

	cout<<node->data<<"\n";

	return 0;
}