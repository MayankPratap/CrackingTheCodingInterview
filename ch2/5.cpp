// Sum Lists

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;


};

Node* Insert(Node* head,int val){  // Insertion at end

	Node* temp=new Node();

	temp->data=val;
	temp->link=NULL;

	if(head==NULL){  // empty list

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

		cout<<temp->data<<"\n";
		temp=temp->link;

	}

}

Node* SumLists(Node* head1,Node* head2){

	int carry=0;
	Node *head=NULL,*temp=NULL;

	while(head1!=NULL || head2!=NULL || carry!=0){

		if(carry!=0 && head1==NULL && head2==NULL){

			Node* temp2=new Node();
			temp2->data=carry;
			temp2->link=NULL;

			if(temp==NULL){

				temp=temp2;
				head=temp;

			}
			else{

				temp->link=temp2;
				temp=temp->link;

			}

			carry=0;


		}

		else if(head1==NULL && head2!=NULL){

			Node* temp2=new Node();
			temp2->data=(carry+head2->data)%10;
			carry=(carry+head2->data)/10;
			temp2->link=NULL;

			if(temp==NULL){

				temp=temp2;
				head=temp;

			}
			else{

				temp->link=temp2;
				temp=temp->link;

			}

			head2=head2->link;


		}

		else if(head1!=NULL && head2==NULL){

			Node* temp2=new Node();
			temp2->data=(carry+head1->data)%10;
			carry=(carry+head1->data)/10;
			temp2->link=NULL;

			if(temp==NULL){

				temp=temp2;
				head=temp;

			}
			else{

				temp->link=temp2;
				temp=temp->link;

			}

			head1=head1->link;

		}

		else if(head1!=NULL && head2!=NULL){

			Node* temp2=new Node();

			temp2->data=(carry+head1->data+head2->data)%10;
			carry=(carry+head1->data+head2->data)/10;

			temp2->link=NULL;

			if(temp==NULL){

				temp=temp2;
				head=temp;

			}

			else{

				temp->link=temp2;
				temp=temp->link;

			}

			head1=head1->link;
			head2=head2->link;

		}

	}

	return head;

}
int main(){

	Node *head1,*head2,*head;
	head1=NULL;
	head2=NULL;
	head=NULL;

	//head1=Insert(head1,1);
	//head1=Insert(head1,0);
	//head1=Insert(head1,6);

	//head2=Insert(head2,9);
	//head2=Insert(head2,9);
	//head2=Insert(head2,9);

	head=SumLists(head1,head2);

	Print(head);

}