#include<bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node *link;

};

Node* top=NULL;

void Push(int x){   // Insert at beginning of linked list

	Node* temp=new Node();
	temp->data=x;
	temp->link=top;

	top=temp;

} 

void Pop(){

	if(top==NULL){  // Empty

		cout<<"Error: No elements to pop";
		return;

	}

	Node* temp=top;
	top=top->link; // Change top to point to next element

	delete temp;

}

int Top(){

	return top->data;

}

bool IsEmpty(){

	if(top==NULL){

		return true;

	}

	else{

		return false;

	}


}

void Print(){

    cout<<"Stack from top to bottom: \n";

    Node *p=top;

    while(p!=NULL){

    	cout<<p->data<<" ";

    	p=p->link;


    }

    cout<<"\n";


}

int main(){

	Push(4);Print();
	Push(9);Print();

	Pop();Print();

	Push(8);Print();
	Pop(); Print();
	Pop(); Print();
	Pop(); Print();




	return 0;
}