// Partition : Partition a linked list around a value x

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

Node* partition(Node* head,int x){

	if(head==NULL){    // empty list
		//cout<<"Hola amigo\n";
		return head;
	}

	Node* p=head;

	Node *first=NULL,*second=NULL,*firstHead=NULL,*secondHead=NULL;

	while(p!=NULL){

		if(p->data<x){

			if(first==NULL){

				first=p;
				firstHead=first;
				//cout<<"Halwa\n";

			}

			else{

				first->link=p;
				first=first->link;
				//cout<<"Bna hai\n";

			}

		}
		else{

			if(second==NULL){

				second=p;
				secondHead=second;
				//cout<<"Sabko\n";

			}
			else{

				second->link=p;
				second=second->link;
				//cout<<"Milega\n";

			}

		}

		p=p->link;

	}

	if(firstHead==NULL && secondHead!=NULL){

		return secondHead;

	}

	else if(firstHead!=NULL && secondHead==NULL){

		first->link=NULL;
		return firstHead;

	}

	first->link=secondHead;
	second->link=NULL;
	return firstHead;


}

void Print(Node* head){

	Node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<" ";
		temp=temp->link;
	}


}

int main(){

	Node* head;
	head=NULL;

	head=Insert(head,8);
	head=Insert(head,3);
	//head=Insert(head,8);
	//head=Insert(head,5);
	//head=Insert(head,10);
	//head=Insert(head,2);
	//head=Insert(head,1);

	//cout<<head->data<<"\n";

	int x;

	x=5;

	//cout<<"Raula machega\n";

	head=partition(head,x);


	Print(head);

	return 0;
}