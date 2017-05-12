// Object Oriented Implementation Using Arrays

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101

class Stack{

private:

	int A[MAX_SIZE];  // array to store the stack
	int top;  // variable to mar top index of stack

public:

	// constructor

	Stack(){

		top=-1; // for empty array, set top=-1;

	}

	void Push(int x){

		if(top==MAX_SIZE-1){  // overflow case.

			printf("Error: Stack Overflow\n");
			return;
		}

		A[++top]=x;

	}

	// Pop operation to remove an element from top of stack
	void Pop(){

		if(top==-1){  // if stack is empty, pop should throw error.

			printf("Error: No element to pop\n");
			return;
		}

		top--;

	}

	int Top(){

		return A[top];

	}

	// This function will return 1 (true) if stack is empty , 0 (false) otherwise
	bool IsEmpty(){

		if(top==-1) return true;
		return false;

	}

	// Only for testing - Not a valid operation with Stack
	void Print(){

		int i;
		printf("Stack: ");

		for(int i=0;i<=top;++i){

			cout<<A[i]<<" ";

		}

		cout<<"\n";


	}

};

int main(){

	// Code to test the implementation
	// calling Print() after each push or pop to see the state of stack

	Stack S;

	S.Push(2);S.Print();
	S.Push(5);S.Print();

	S.Push(10);S.Print();

	S.Pop();S.Print();

	S.Push(12);S.Print();




}