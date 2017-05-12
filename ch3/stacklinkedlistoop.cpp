#include<bits/stdc++.h>
using namespace std;

class Stack{

private:

	struct Node{
		int data;
		Node *link;

	};

	Node* top;

public:

	// constructor - used to initialize variables

	Stack(){

		top=NULL;


	}

	void Push(int x){

		Node* temp=new Node();
		temp->data=x;
		temp->link=top;

		top=temp;

	}

	void Pop(){

		if(top==NULL){   // Empty

			cout<<"Error: No elements to pop\n";
			return;
		}

		Node* temp=top;
		top=top->link;   // Change top to point to next element

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

		cout<<"Stack from top to bottom\n";
		Node *p=top;

		while(p!=NULL){

			cout<<p->data<<" ";
			p=p->link;


		}

		cout<<"\n";


	}
};

int main(){

	Stack S;

	S.Push(4); S.Print();
	S.Push(9); S.Print();
	S.Pop(); S.Print();

	S.Push(8); S.Print();
	S.Pop();  S.Print();
	S.Pop(); S.Print();
	S.Pop(); S.Print();

	return 0;

}

