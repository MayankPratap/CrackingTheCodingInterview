#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;

void Push(int x){

	if(top==MAX_SIZE-1){

		cout<<"Stack Overflow\n";
		return;
	}

	A[++top]=x;

}

void Pop(){

	if(top==-1){

		cout<<"No element to pop\n";
		return;

	}

	top--;

}

int Top(){

	return A[top];

}



int main(){

	Push(2);
	Push(5);
	Push(10);
	Pop();
	Push(12);
	

	return 0;
}