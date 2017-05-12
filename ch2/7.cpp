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

int get_length(Node* head){

	int cnt=0;

	while(head!=NULL){

		cnt+=1;
		head=head->link;

	}

	return cnt;
}

Node* intersect(Node *first,Node *second){

	int length_first=get_length(first);
	int length_second=get_length(second);

	Node *ans=NULL;

	if(length_first>=length_second){

		int diff=length_first-length_second;

		Node *p=first;

		while(diff){

			p=p->link;
			diff--;
		}

		Node *q=second;

		while(p!=NULL && q!=NULL){

			if(p==q){

				ans=p;
				break;

			}

			else{

				p=p->link;
				q=q->link;

			}

		}

		return ans;
	}

	else{

		int diff=length_second-length_first;

		Node *q=second;

		while(diff){

			q=q->link;
			diff--;
		}

		Node *p=first;

		while(p!=NULL && q!=NULL){

			if(p==q){

				ans=p;
				break;

			}

			else{

				p=p->link;
				q=q->link;

			}

		}

		return ans;


	}


}

int main(){

	Node *head1,*head2,*ans;
	head1=NULL;
	head2=NULL;

	head1=Insert(head1,1);
	head1=Insert(head1,2);
	head1=Insert(head1,3);
	head1=Insert(head1,7);

	head2=Insert(head2,4);
	head2=Insert(head2,5);

	//Node* p=head2;
	//while(p->link!=NULL){

	//	p=p->link;

//	}

	//p->link=head1->link;

	ans=intersect(head1,head2);

	if(ans!=NULL){

		cout<<ans->data<<"\n";

	}
	else{

		cout<<"Linked lists do not intersect\n";

	}
	//head2=Insert(head2,9);
	//head2=Insert(head2,9);
	//head2=Insert(head2,9);
	
  

}