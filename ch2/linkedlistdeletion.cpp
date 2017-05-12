#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* link;
};

Node* head;  // global
void Insert(int data);  // insert at beginning
void Print();   // print all elements in the list
void Delete(int n);   // delete node at nth position

void Insert(int x){  // Insert at beginning of linked list
	Node* temp=new Node();
    // temp is pointer variable 
    // and I am dereferencing pointer variable
    // to access the node
	temp->data=x;
  	temp->link=head;  // If list was empty head was null so no probs
  	head=temp;
}

void Print(){

	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\n";
		temp=temp->link;
	}
	cout<<"\n";
}

void Delete(int n){  // 1 based indexing
	Node* temp1=head;
	if(n==1){
		head=temp1->link; // head now points to second node
		delete temp1;
		return; 
	}
	int i;
	for(i=0;i<n-2;++i){
		temp1=temp1->link;
	}
	// temp1 points to (n-1) th Node
	Node* temp2=temp1->link; // nth node
	temp1->link=temp2->link;  // n-1th node now points to n+1 th node
	delete temp2;

}

int main(){

	head=NULL; // empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(7);   // List: 2,4,6,5

	Print();

	int n;

	cout<<"Enter a position to delete\n";

	cin>>n;

	Delete(n);

	Print();

	return 0;
}