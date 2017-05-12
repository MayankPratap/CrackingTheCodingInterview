#include<bits/stdc++.h>
using namespace std;



struct Node{

	int data;
	Node* link;


};

Node* head;

void Insert(int x){  // Insert at beginning of linked list
	Node* temp=new Node();
    // temp is pointer variable 
    // and I am dereferencing pointer variable
    // to access the node
	temp->data=x;
  	temp->link=head;  // If list was empty head was null so no probs
  	head=temp;
}

void Print(Node* p){
	if(p==NULL) return;
	cout<<p->data<<" ";
	Print(p->link);

}

void PrintReverse(Node* p){

	if(p==NULL) return;

	PrintReverse(p->link);

	cout<<p->data;

}

int main(){

	head=NULL; // empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(7);   // List: 2,4,6,5

	Print(head);

	PrintReverse(head);


}