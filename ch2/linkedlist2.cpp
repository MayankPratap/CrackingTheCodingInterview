// Implementation Of Linked List In C++

// Insertion with address of head sent to function
// Pointer to Pointer concept used.

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;

};


void Insert(Node** head,int x){  // Insert at beginning of linked list

	Node* temp=new Node();
    // temp is pointer variable 
    // and I am dereferencing pointer variable
    // to access the node
	temp->data=x;
  	temp->link=*head;  // If list was empty head was null so no probs
  	*head=temp;


}

void Print(Node* head){

	Node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<"\n";
		temp=temp->link;

	}

	cout<<"\n";


}

int main(){

	Node* head;

	head=NULL;  // list is empty

	printf("How many numbers?\n");

	int n,i,x;

	cin>>n;

	for(i=0;i<n;++i){

		cout<<"Enter the number: \n";
		cin>>x;

		Insert(&head,x);

	}

	Print(head);

}