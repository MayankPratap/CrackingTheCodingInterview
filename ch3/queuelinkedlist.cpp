#include<bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;

};

// Two global variables to store address of front and rear nodes

Node* front=NULL;
Node* rear=NULL;

// To enqueue an integer  // Insert at end

void Enqueue(int x){

	Node* temp=new Node();

	temp->data=x;
	temp->link=NULL;

	if(front==NULL && rear==NULL){

		front=read=temp;
		return;

	}

	rear->link=temp;
	rear=temp;

}

void Dequeue(){  // Remove from beginning

	Node* temp=front;

	if(front==NULL){

		cout<<"Queue is empty\n";
		return;
	}

	if(front==rear){

		// Single element is list currently

		front=rear=NULL;

	}

	else{

		front=front->link;

	}

	delete temp;

}

int Front(){

	if(front==NULL){

		cout<<"Queue is empty\n";
		return;

	}

	return front->data;

}


void Print(){

	Node *temp=front;

	while(temp!=NULL){

		cout<<temp->data<<" ";
		temp=temp->link;

	}

	cout<<"\n";
}


int main(){

	Enqueue(2); Print();

	Enqueue(4); Print();

	Enqueue(6); Print();

	Dequeue(); Print();

	Enqueue(8); Print();



}