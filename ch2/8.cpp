
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

Node* detectLoopStart(Node* head){

	if(head==NULL){

		return head;
	}

	Node *slow=head,*fast=head;
	Node *p=head;

	slow=slow->link;
	fast=fast->link->link;

	while(slow!=fast){

		slow=slow->link;
		fast=fast->link->link;

	}

	while(p!=slow){

		p=p->link;
		slow=slow->link;

	}

	return p;

}

int main(){

	Node *head;
	head=NULL;

	head=Insert(head,1);
	head=Insert(head,2);
	//head=Insert(head,3);
	//head=Insert(head,4);
	//head=Insert(head,5);
	//head=Insert(head,6);
	//head=Insert(head,7);
	//head=Insert(head,8);
	//head=Insert(head,9);

	Node *p=head;

	while(p->link!=NULL){

		p=p->link;
	}

	p->link=head;

	Node *ans=detectLoopStart(head);

	cout<<ans->data<<"\n";


	return 0;
}

